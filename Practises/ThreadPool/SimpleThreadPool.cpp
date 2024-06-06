#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <vector>
#include <functional>
#include <thread>

class SimpleThreadPool {
public:
    SimpleThreadPool(size_t);
    ~SimpleThreadPool();

    //添加任务到线程池
    void enqueue(std::function<void()> func);

private:
    //需要持续跟踪的线程池
    std::vector<std::thread> workers;
    //任务队列
    std::queue<std::function<void()>> tasks;

    //同步机制
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

SimpleThreadPool::SimpleThreadPool(size_t threads) 
    : stop(false)
{
    for(int i = 0; i < threads; ++i) {
        workers.emplace_back(
            [this] {
                for(;;) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                            [this] { return this->stop || !this->tasks.empty();});
                        if(this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    task();
                }
            }
        );
    }
}

SimpleThreadPool::~SimpleThreadPool() 
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker : workers)
        worker.join();
}

void SimpleThreadPool::enqueue(std::function<void()> func) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        if(stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }

        tasks.emplace(func);
    }
    condition.notify_one();
}

int main() {
    SimpleThreadPool pool(4);

    for(int i = 0; i < 8; ++i) {
        pool.enqueue([i] {
            std::cout << "Task" << i << " is executing." << std::endl;
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("pause");
    return 0;
}
