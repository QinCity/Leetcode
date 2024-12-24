/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> order;
        if (!root)
            return root;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            for (int i = 0; i < layer_size; i++) {
                TreeNode *cur, *tmp;
                cur = order.front();
                order.pop();
                tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;
                if (cur->left)
                    order.push(cur->left);
                if (cur->right)
                    order.push(cur->right);
            }
        }
        return root;
    }
};
// @lc code=end

