/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(char c : s) {
            ++mp[c];
        }

        for(int i = 0; i < s.size(); ++i) {
            if(mp[s[i]] == 1) return i;
        }

        return -1;
    }
};
// @lc code=end

