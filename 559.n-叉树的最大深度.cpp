/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> order;
        int depth = 0;
        if (!root)
            return depth;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            depth++;
            for (int i = 0; i < layer_size; i++) {
                Node* cur = order.front();
                order.pop();
                for (auto j: cur->children) {
                    order.push(j);
                }
            }
        }
        return depth;
    }
};
// @lc code=end

