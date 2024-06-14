/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        long long x = 0 , num = 0;
        int index = 0, n = equation.size();
        bool isRiht = false;
        while(index < n) {

            if(equation[index] == '=') {
                isRiht = true;
                index++;
            }

            int sign = 1;
            if(equation[index] == '-' || equation[index] == '+') {
                sign = (equation[index] == '+') ? 1 : -1;
                index++;
            }

            if(isRiht) sign *= -1;

            int temp = 0;
            while(index < n && isdigit(equation[index])) {
                temp = temp * 10 + equation[index] - '0';
                index++;
            }

            temp *= sign;
            if(equation[index] == 'x') {
                if(index != 0 && equation[index - 1] == '0') ;
                else if(temp == 0) x += sign;
                else x += temp;
                index++;
            }
            else num += temp;
            
        }

        if(x == 0) return (num == 0) ? "Infinite solutions" : "No solution";
        else return "x=" + to_string(- num / x); 
    }
};
// @lc code=end

