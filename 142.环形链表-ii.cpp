/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //快慢指针
        ListNode *down = head;
        ListNode *up = head;
    }
};
// @lc code=end


//---------法一：哈希-------------(这道题最好用hash_set)
        // unordered_map<ListNode*, int> exist;
        // ListNode* cur = head;
        // while(cur != NULL) {
        //     if (exist.find(cur) == exist.end()) 
        //         exist[cur] = 1;
        //     else {
        //         return cur; 
        //     }
        //     cur = cur->next;
        // }
        // return NULL;


