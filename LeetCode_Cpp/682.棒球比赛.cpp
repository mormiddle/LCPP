/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        vector<int> arrPoint;
        for(string& op : operations) {
            int n = arrPoint.size();
            int temp = 0;
            switch (op[0])
            {
            case '+':
                temp = arrPoint[n-1] + arrPoint[n-2];
                arrPoint.emplace_back(temp);
                ans += temp;
                break;
            case 'D':
                temp = 2 * arrPoint[n-1];
                arrPoint.emplace_back(temp);
                ans += temp;
                break;
            case 'C':
                temp = arrPoint[n-1];
                arrPoint.pop_back();
                ans -= temp;
                break;    
            default:
                temp = stoi(op);
                arrPoint.emplace_back(temp);
                ans += temp;
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

