/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool isMatching(string& query, string& pattern) {
        int pIndex = 0;
        for (auto& c : query) {
            if (pIndex < pattern.size() && c == pattern[pIndex]) {
                ++pIndex;
            } else if (isupper(c)) {
                return false;
            }
        }

        return pIndex == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer;
        for (auto& query : queries) {
            answer.emplace_back(isMatching(query, pattern));
        }
        return answer;
    }
};
// @lc code=end
