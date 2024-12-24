/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> order;
        if (!root)
            return root;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            Node *cur;
            for (int i = 0; i < layer_size; i++) {
                cur = order.front();
                order.pop();
                if (i != layer_size - 1)
                    cur->next = order.front();
                if (cur->left != NULL)
                    order.push(cur->left);
                if (cur->right != NULL) {
                    order.push(cur->right);
                }
            }
        }
        return root;
    }
};
// @lc code=end

