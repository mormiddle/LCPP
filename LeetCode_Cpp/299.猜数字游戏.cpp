/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int ansForSecrent = 0;
        vector<int> coutS(10);
        vector<int> coutG(10);
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                ansForSecrent++;
            }
            else {
                ++coutG[guess[i] - '0'];
                ++coutS[secret[i] - '0'];
            }
        }

        int ansForGuess = 0;
        for(int i = 0; i < 10; i++) {
            ansForGuess += min(coutG[i], coutS[i]);
        }

        return to_string(ansForSecrent) + 'A' + to_string(ansForGuess) + 'B';
    }
};
// @lc code=end

