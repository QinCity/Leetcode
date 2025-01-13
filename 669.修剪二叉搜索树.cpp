/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* deleteMin(TreeNode* root, int low) {
        if (root == nullptr)
            return nullptr;
        if (root->val >= low) {
            root->left = deleteMin(root->left, low);
            return root;
        }  
        else {
            return deleteMin(root->right, low);
        }   
    }

    TreeNode* deleteMax(TreeNode* root, int max) {
        if (root == nullptr)
            return nullptr;
        if (root->val <= max) {
            root->right = deleteMax(root->right, max);
            return root;
        }  
        else {
            return deleteMax(root->left, max);
        }   
    } 

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = deleteMax(root, high);
        root = deleteMin(root, low);
        return root;
    }
};
// @lc code=end

