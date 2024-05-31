/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26);
        int k = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i && (s[i] - s[i-1] + 26) % 26 == 1) {
                k++;
            }else {
                k = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'] , k);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end

