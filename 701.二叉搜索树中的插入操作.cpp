/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        if (root == nullptr)
            return new TreeNode(val);
        while (cur != nullptr) {
            TreeNode* tmp_node = val > cur->val ? cur->right : cur->left;
            if (tmp_node == nullptr) {
                if (val > cur->val)
                    cur->right = new TreeNode(val);
                else
                    cur->left = new TreeNode(val);
                    break;
            }
            cur = tmp_node;
        }
        return root;
    }
};
// @lc code=end

