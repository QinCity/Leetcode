/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        while (head == NULL || head->next == NULL)
            return head;
        
        ListNode* back = head->next;
        head->next = swapPairs(back->next);
        back->next = head;
        head = back;
        return head;
    }
};
// @lc code=end

// ------------法一------------
        // ListNode* cur = head;
        // if (cur != NULL && cur->next != NULL) {
        //     ListNode* tmp = cur->next->next;
        //     head = cur->next;
        //     cur->next->next = cur;
        //     cur->next = tmp;
        // } 
        // else {
        //     return head;
        // }

        // while (cur->next != NULL && cur->next->next != NULL) {
        //     ListNode* back = cur->next->next;
        //     ListNode* front = cur->next;
        //     cur->next = back;
        //     front->next = back->next;
        //     back->next = front;
        //     cur = front;
        // }
        // return head;