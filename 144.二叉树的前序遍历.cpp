/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> order;
        vector<int> result;
        if (root == NULL)
            return result;
        order.push(root);
        while (!order.empty()) {
            TreeNode* tmp;
            tmp = order.top();
            order.pop();
            result.push_back(tmp->val);
            if (tmp->right != NULL)
                order.push(tmp->right);
            if (tmp->left != NULL)
                order.push(tmp->left); 
        }
        return result;
    }

};
// @lc code=end


//法一：递归
    // void preorder(vector<int>& result, TreeNode* cur_node) {
    //     if (cur_node == NULL) {
    //         return;
    //     }
    //     result.push_back(cur_node->val);
    //     preorder(result, cur_node->left);
    //     preorder(result, cur_node->right);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     preorder(result, root);
    //     return result;
    // }