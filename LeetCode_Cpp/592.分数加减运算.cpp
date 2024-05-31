/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionAddition(string expression) {
        regex re("\\+|\\/");
        vector<string> complex1(sregex_token_iterator(expression.begin(), expression.end(), re, -1), std::sregex_token_iterator());

        int ansFz = 0, ansFm = 0;
        

        if(ansFz == 0) return "0/1";

        if(ansFz % ansFm == 0) {
            if(ansFz > ansFm) {
                ansFz = ansFz / ansFm;
                ansFm = 1;
            }
            else {
                ansFm = ansFm /ansFz;
                ansFz = 1;
            }
        }

        return to_string(ansFz) + "/" + to_string(ansFm);
    }
};
// @lc code=end

