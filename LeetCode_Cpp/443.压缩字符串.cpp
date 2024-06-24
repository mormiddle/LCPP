/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int anchor = 0, write = 0;
        for(int read = 0 ; read < n; read++) {
            if(read + 1 == n || chars[read] != chars[read + 1]) {
                chars[write++] = chars[anchor];
                if(read > anchor) {
                    string str = to_string(read - anchor + 1);
                    for(char c : str) chars[write++] = c;
                }
                
                anchor = read + 1;
            }
            
        }
        return write;
    }
};
// @lc code=end

