/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* front = NULL;
        ListNode* back = head;
        while (back != NULL) {
            ListNode* tmp = back->next;
            back->next = front;
            front  = back;
            back = tmp;
        }
        head = front;
        return head;
         
    }
};
// @lc code=end

//-----------------法一-------------------
        // ListNode* cur = head;
        // ListNode* back;
        // if (cur == NULL || cur->next == NULL)
        //     return head;
        // else {
        //     back = head->next;
        //     head->next = NULL;
        // }

        // cur = back;
        // while (cur->next != NULL) {
        //     back = cur->next;
        //     cur->next = head;
        //     head = cur;
        //     cur = back;
        // }
        // cur->next = head;
        // head = cur;
        // return head;