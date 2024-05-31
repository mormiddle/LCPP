/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int strBeg = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') continue;
            int tempStrBeg = strBeg;
            while(i < n && s[i] != ' ') {
                s[tempStrBeg++] = s[i++];
            }
            reverse(s.begin() + strBeg, s.begin() + tempStrBeg);
            strBeg = tempStrBeg;
            s[strBeg++] = ' ';
        }
        s.erase(s.begin() + strBeg - 1, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
// @lc code=end

