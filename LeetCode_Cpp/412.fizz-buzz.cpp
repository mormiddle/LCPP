/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++) {
            if( i % 3 == 0 && i % 5 == 0) ans.emplace_back("FizzBuzz");       
            else if( i % 3 == 0) ans.emplace_back("Fizz");
            else if( i % 5 == 0) ans.emplace_back("Buzz");
            else ans.emplace_back(to_string(i));
        }
        return ans;
    }
};
// @lc code=end

