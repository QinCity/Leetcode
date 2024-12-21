/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> back;
        vector<int> result;
        if (root == NULL)
            return result;
        back.push(root);
        while (!back.empty()) {
            TreeNode* cur = back.top();
            back.pop();
            result.push_back(cur->val);
            if (cur->left != NULL) {
                back.push(cur->left);
            }
            if (cur->right != NULL) {
                back.push(cur->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

