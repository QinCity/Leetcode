/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int getVal(TreeNode* root) {
        if (!root)
            return 0;
        return root->val;
    }
    void traverse(TreeNode* root, int &self_val, int &child_val) {
        if (root == NULL) {
            self_val = 0;
            child_val = 0;
            return;
        }
        int first_fl_l, second_fl_l, first_fl_r, second_fl_r;
        traverse(root->left, first_fl_l, second_fl_l);
        traverse(root->right, first_fl_r, second_fl_r);

        self_val = max(root->val + second_fl_l + second_fl_r, first_fl_r + first_fl_l);
        child_val = first_fl_r + first_fl_l;


        // TreeNode* dp_root;
        // TreeNode* dp_left = traverse(root->left);
        // TreeNode* dp_right= traverse(root->right);
        // int left_val = dp_left == NULL? 0; dp_left->val;
        // int right_val = 

    }
    int rob(TreeNode* root) {
        int first, second;
        traverse(root, first, second);
        return first; 
    }
};
// @lc code=end

