/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMinTime(string &t) {
        return ((int(t[0] - '0') * 10 + int(t[1] - '0')) * 60 + int(t[3] - '0') * 10 + int(t[4] - '0')) ;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int ans = INT_MAX;
        int t0Time = getMinTime(timePoints[0]);
        for(int i = 1; i < n; i++) {
            int tempTime = getMinTime(timePoints[i]) - getMinTime(timePoints[i-1]);
            ans = min(ans, tempTime);
        }

        ans = min(ans, (t0Time + 1440 - getMinTime(timePoints[n-1])));
        return ans;
    }
};
// @lc code=end

