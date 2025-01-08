/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
int min_difference = 100000;
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

    void getMin(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* root_left = rightmost(root->left);
        TreeNode* root_right = leftmost(root->right);
        if (root_left)
            min_difference = (root->val - root_left->val) < min_difference ?  (root->val - root_left->val) : min_difference;
        if (root_right)
            min_difference = (root_right->val - root->val) < min_difference ?  (root_right->val - root->val) : min_difference;
        getMin(root->right);
        getMin(root->left);  
    }
    int getMinimumDifference(TreeNode* root) {
        getMin(root);
        return min_difference;

    }
};
// @lc code=end

