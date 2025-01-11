/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* findMax(TreeNode* root) {
        TreeNode* cur = root;
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        return cur; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur = root, *cur_father = nullptr;
        while (cur != nullptr && cur->val != key) {
            cur_father = cur;
            if (cur->val > key)
                cur = cur->left;
            else 
                cur = cur->right;
        }
        if (cur == nullptr)
            return root;
        if (cur_father == nullptr) { 
            if (cur->left == nullptr)
                root = cur->right;
            else if (cur->right == nullptr)
                root = cur->left;
            else {
                TreeNode* tmp = findMax(root->left);
                tmp->left = deleteNode(root->left, tmp->val);
                tmp->right = root->right;
                root = tmp;
            }
        } 
        else {
            if (cur->left == nullptr) {
               if (cur_father->val > cur->val)
                    cur_father->left = cur->right;
                else {
                    cur_father->right = cur->right;
                } 
            }
            else if (cur->right == nullptr) {
                if (cur_father->val > cur->val)
                    cur_father->left = cur->left;
                else {
                    cur_father->right = cur->left;
                } 
            }
            else {
                TreeNode* tmp = findMax(cur->left);
                tmp->left = deleteNode(cur->left, tmp->val);
                tmp->right = cur->right;
                if (cur_father->val > tmp->val)
                    cur_father->left = tmp;
                else {
                    cur_father->right = tmp;
                }
            }
        }
        return root;
    }
};
// @lc code=end

