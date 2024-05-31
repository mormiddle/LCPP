/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        regex re("/");
        vector<string> names(sregex_token_iterator(path.begin(), path.end(), re, -1), std::sregex_token_iterator());

        vector<string> stacks;
        for(auto& name : names) {
            if(name == "..") {
                if(!stacks.empty()) stacks.pop_back();
            }
            else if(!name.empty() && name != ".") {
                stacks.emplace_back(name);
            }
        }

        if(stacks.size() == 0) return "/";

        string ans;
        for(int i = 0; i < stacks.size(); i++) {
            ans += "/";
            ans += stacks[i];
        }

        return ans;
    }
};
// @lc code=end

