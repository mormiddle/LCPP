/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return to_string(nums[0]);
        if(n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);

        string ans = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for(int i = 2; i < n; i++) {
            ans += "/" + to_string(nums[i]);
        }
        ans += ")";
        return ans;
    }
};
// @lc code=end

