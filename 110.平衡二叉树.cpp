/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int isBalance(TreeNode* root) {
        if (!root)
            return 0;
        int left_height = isBalance(root->left);
        int right_height = isBalance(root->right);
        if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
            return -1;
        else {
            return max(left_height, right_height) + 1;
        }
        
    }

    bool isBalanced(TreeNode* root) {
        return isBalance(root) >= 0;
    }
};
// @lc code=end

