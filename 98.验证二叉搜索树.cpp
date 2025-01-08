/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode* rightmost(TreeNode* root) {
        if (!root)
            return nullptr;
        while (root->right) {
            root = root->right;
        }
        return root;
    }
    TreeNode* leftmost(TreeNode* root) {
        if (!root)
            return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (!isValidBST(root->right))
            return false;
        if (!isValidBST(root->left))
            return false;
        TreeNode* root_left = rightmost(root->left);
        TreeNode* root_right = leftmost(root->right);
        if (root_left) {
            if (root_left->val >= root->val) {
                return false;
            }
        }
        if (root_right) {
            if (root_right->val <= root->val)
                return false;
        }
        return true;
    }
};
// @lc code=end

