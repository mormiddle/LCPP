#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <future>
#include <stdexcept>
#include <functional>
#include <condition_variable>

class ThreadPool 
{
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        ->std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();

private:
    //创建一个容器容纳工作的线程
    std::vector<std::thread> workers;
    //任务队列
    std::queue<std::function<void()>> tasks;

    //同步
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// 构造函数只是启动一定数量的工作线程
inline ThreadPool::ThreadPool(size_t threads) 
{
    for(int i = 0; i < threads; ++i) {
       workers.emplace_back(
        [this] 
        {
            for(;;) 
            {
                std::function<void()> task;

                {
                    std::unique_lock<std::mutex> lock(queue_mutex);
                    this->condition.wait(lock, 
                        [this] {return this->stop || !this->tasks.empty();});
                    if(this->stop && this->tasks.empty()) 
                        return;
                    task = std::move(tasks.front());
                    this->tasks.pop();
                }

                task();
            }
        }
       );
    }
}

template <class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type> {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>> (
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            //如何线程池停止，则不允许加入新任务
            if(stop) {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }

            tasks.emplace([task](){ (*task)();});
        }
    condition.notify_one();
    return res;
}


inline ThreadPool::~ThreadPool() 
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }

    condition.notify_all();
    for(std::thread &worker : workers) {
        worker.join();
    }
}