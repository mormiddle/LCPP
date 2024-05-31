/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s) {
            ++mp[c];
        }

        vector<pair<char, int>> waitSort;
        for(auto c : mp) {
            waitSort.emplace_back(c);
        }
        sort(waitSort.begin(), waitSort.end(), [](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second;
        });

        string ans;
        for(auto& [ch, num] : waitSort) {
            for(int i = 0; i < num; i++) {
                ans += ch;
            }
        }

        return ans;
    }
};
// @lc code=end

