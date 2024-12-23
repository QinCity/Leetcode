/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> order;
        if (!root)
            return result;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            TreeNode* cur;
            double sum = 0;
            for (int i = 0; i < layer_size; i++) {
                cur = order.front();
                order.pop();
                if (cur->left != NULL)
                    order.push(cur->left);
                if (cur->right != NULL) 
                    order.push(cur->right);
                sum += cur->val;
            }
            result.push_back(sum/layer_size);
        }
        return result; 
    }
};
// @lc code=end

