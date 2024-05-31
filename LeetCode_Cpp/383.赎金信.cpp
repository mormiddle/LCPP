/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> mp;

        for(char c : magazine) {
            ++mp[c];
        }

        for(char c : ransomNote) {
            if(--mp[c] < 0) return false;
        }

        return true;
        
    }
};
// @lc code=end

