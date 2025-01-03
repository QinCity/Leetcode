/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    void deep_reverse(TreeNode* cur, int sum, bool &is_true, int target_sum) {
        sum += cur->val;
        if (!cur->left && !cur->right) {
            if (sum == target_sum)
                is_true = true;
            return;
        }
        if (cur->left)
            deep_reverse(cur->left, sum, is_true, target_sum);
        if (cur->right)
            deep_reverse(cur->right, sum, is_true, target_sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool is_true = 0;
        if (!root) {
            return false;
        }
        deep_reverse(root, sum, is_true, targetSum);
        return is_true;                
    }
};
// @lc code=end

