/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || !head->next) return head;
        
        ListNode* old_temp = head;
        int n = 1;
        while(old_temp->next) {
            old_temp = old_temp->next;
            n++;
        }

        old_temp->next = head;
        k = k % n;
        ListNode* new_temp = head;
        for(int i = 0; i < n - k - 1; i ++) {
            new_temp = new_temp->next;
        }

        ListNode* new_hand = new_temp->next;
        new_temp->next = nullptr;

        return new_hand;
    }


};
// @lc code=end
