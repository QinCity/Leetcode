/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> order;
        if (!root)
            return result;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            TreeNode* cur;
            for (int i = 0; i < layer_size; i++) {
                cur = order.front();
                order.pop();
                if (cur->left != NULL)
                    order.push(cur->left);
                if (cur->right != NULL) 
                    order.push(cur->right);
            }
            result.push_back(cur->val);
        }
        return result;
    }
};
// @lc code=end

