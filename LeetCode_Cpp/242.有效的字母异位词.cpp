/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> mp;
        for(char c : s) {
            ++mp[c];
        }

        for(char c : t) {
            if(--mp[c] < 0) return false;
        }
        
        return true ;

    }
};
// @lc code=end

