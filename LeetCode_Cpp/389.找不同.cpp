/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(char c : s) {
            ++mp[c];
        }

        for(char c: t) {
            if(--mp[c] < 0) return c;
        }

        return ' ';
    }
};
// @lc code=end

