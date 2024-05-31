/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].emplace_back(str);
        }

        vector<vector<string>> ans;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            ans.emplace_back(i->second);
        }
        return ans;
    }
};
// @lc code=end

