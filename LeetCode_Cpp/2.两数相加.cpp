/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dumyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* currL = dumyHead;
        int carry = 0;

        while(l1  || l2 ) {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;
            int sum = x + y + carry;

            carry = sum / 10;
            currL->next =new ListNode(sum%10);
            currL = currL->next;
            l1 ? l1=l1->next : 0;
            l2 ? l2=l2->next : 0;
        }
        if(carry > 0) {
            currL->next = new ListNode(carry);
        }

        return dumyHead->next;
    }
    }
};
// @lc code=end

