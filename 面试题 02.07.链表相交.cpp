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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = 0;
        int length_b = 0;

        ListNode* tmp = headA;
        while (tmp != NULL) {
            length_a++;
            tmp = tmp->next;
        }
        tmp = headB;
        while (tmp != NULL) {
            length_b++;
            tmp = tmp->next;
        }
        ListNode* tmp_a = headA;
        ListNode* tmp_b = headB;
        if (length_a > length_b) {
            for (int i = length_a -length_b; i > 0; i--) {
                tmp_a = tmp_a->next;
            }
            while (tmp_a != NULL) {
                if (tmp_a == tmp_b)
                    return tmp_a;
                tmp_a = tmp_a->next;
                tmp_b = tmp_b->next;
            }
        }
        else {
            for (int i = length_b -length_a; i > 0; i--) {
                tmp_b = tmp_b->next;
            }
            while (tmp_b != NULL) {
                if (tmp_a == tmp_b)
                    return tmp_a;
                tmp_a = tmp_a->next;
                tmp_b = tmp_b->next;
            }
        }
        return NULL;     
    }
};