/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> order;
        int sum = 0;
        if (!root)
            return sum;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            for (int i = 0; i < layer_size; i++) {
                TreeNode* tmp = order.front();
                order.pop();
                sum++;
                if (tmp->left)
                    order.push(tmp->left);
                if (tmp->right)
                    order.push(tmp->right);
            }
        }
        return sum;
    }
};
// @lc code=end

