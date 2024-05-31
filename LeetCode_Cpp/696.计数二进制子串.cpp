/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countBinarySubstrings(string s) {
        int lastCount = 0;
        int ptr = 0;
        int n = s.size();
        int ans = 0;
        while (ptr < n) {
            int currCount = 0;
            char currChar = s[ptr];
            while (ptr < n && s[ptr] == currChar) {
                currCount++;
                ptr++;
            }
            ans += min(lastCount, currCount);
            lastCount = currCount;
        }
        return ans;

    }
};
// @lc code=end
