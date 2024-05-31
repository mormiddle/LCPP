/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        string desc[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int n = score.size();
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++) {
            arr.emplace_back(make_pair(-score[i], i));
        }
        sort(arr.begin(), arr.end());

        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            if(i < 3) ans[arr[i].second] = desc[i];
            else ans[arr[i].second] = to_string(i+1);
        }
        return ans;

    }
};
// @lc code=end

