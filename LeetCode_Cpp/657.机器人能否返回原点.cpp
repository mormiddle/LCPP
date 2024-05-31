/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        if(n == 1) return false;

        int x = 0, y = 0;
        for(int i = 0; i < n; ++i) {
            if('R' == moves[i]) x++;
            if('L' == moves[i]) x--;
            if('U' == moves[i]) y++;
            if('D' == moves[i]) y--;
        }

        if(x == 0 && y == 0) return true;
        else return false;

    }
};
// @lc code=end

