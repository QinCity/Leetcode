/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> order;
        int min_depth = 0;
        if (!root)
            return 0;
        order.push(root);
        while (!order.empty()) {
            min_depth++;
            int layer_size = order.size();
            for (int i = 0; i < layer_size; i++) {
                TreeNode* cur = order.front();
                order.pop();
                if (!cur->left && !cur->right)
                    return min_depth;
                if (cur->left)
                    order.push(cur->left);
                if (cur->right)
                    order.push(cur->right); 
            }
        }
        return min_depth;
    }
};
// @lc code=end

