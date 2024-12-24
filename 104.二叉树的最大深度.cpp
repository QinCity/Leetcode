/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// @lc code=end

// 法一:层次遍历
        // int depth = 0;
        // queue<TreeNode*> order;
        // if (!root) {
        //     return depth;
        // }
        // order.push(root);
        // while (!order.empty()) {
        //     int layer_size = order.size();
        //     for (int i = 0; i < layer_size; i++) {
        //         TreeNode* cur = order.front();
        //         order.pop();
        //         if (cur->left)
        //             order.push(cur->left);
        //         if (cur->right)
        //             order.push(cur->right);
        //     }
        //     depth++;
        // }
        // return depth;