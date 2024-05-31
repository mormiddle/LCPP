/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0, countL = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A') countA++;
            if(countA > 1) return false;
            if(s[i] == 'L') countL++;
            else countL = 0;
            if(countL > 2) return false;
        }
        return true;

    }
};
// @lc code=end

