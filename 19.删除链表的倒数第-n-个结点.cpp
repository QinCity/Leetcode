/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* back = head;
        for(int i = 1; i <= n - 1; i++) {
            back = back->next;
        } 
        ListNode* front = head;
        while (back->next != NULL) {
            back = back->next;
            if (back->next == NULL) {
                front->next = front->next->next;
                return head;
            }
            front = front->next;
        }
        head = head->next;
        return head;
    }
};
// @lc code=end

