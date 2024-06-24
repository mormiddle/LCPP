/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; i++) {
            int start = 0, post = 0;
            string cur = "";

            while (post < prev.size()) {
                while (post < prev.size() && prev[post] == prev[start]) {
                    post++;
                }
                cur += to_string(post - start) + prev[start]; 
                start = post; 
            }
            prev = cur;
        }
        return prev;
    }
};
// @lc code=end
