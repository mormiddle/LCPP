/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        int currLeft = 0, currRight = 0, nextLeft = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                currRight = i - 1;
                nextLeft = i + 1;
                while(currLeft < currRight) {
                    swap(s[currLeft], s[currRight]);
                    currLeft++;
                    currRight--;
                }
                currLeft = nextLeft;
            }

            if(i == n -1) {
                currRight = i;
                while(currLeft < currRight) {
                    swap(s[currLeft], s[currRight]);
                    currLeft++;
                    currRight--;
                }
            }
        }

        return s;
    }
};
// @lc code=end
