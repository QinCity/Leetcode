/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void order(vector<vector<int>> &result, int depth, TreeNode* cur) {
        if (!cur)
            return;
        if (result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(result, depth + 1, cur->left);
        order(result, depth + 1, cur->right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> layer;
        vector<vector<int>> results;
        order(results, 0, root);        
        return results;
    }
};
// @lc code=end

// 法一:迭代法
        // queue<TreeNode*> layer;
        // vector<vector<int>> results;
        // if (root != NULL) {
        //     layer.push(root);
        // }
        // while (!layer.empty()) {
        //     int layer_size = layer.size();
        //     vector<int> result;
        //     for (int i = 0; i < layer_size; i++) {
        //         TreeNode* cur = layer.front();
        //         layer.pop();
        //         result.push_back(cur->val);
        //         if (cur->left != NULL)
        //             layer.push(cur->left);
        //         if (cur->right != NULL) 
        //             layer.push(cur->right);
        //     }
        //     results.push_back(result);
        // }
        // return results;