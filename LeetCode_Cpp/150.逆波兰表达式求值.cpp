/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            string& token = tokens[i];
            if(isNumber(token)) {
                st.push(stoi(token));
            }
            else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (token[0])
                {
                case '+':
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num1 - num2);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                case '/':
                    st.push(num1 / num2);
                    break;
                }
            }
        }
        return st.top();
        

    }

    bool isNumber(string s) {
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }
};
// @lc code=end

