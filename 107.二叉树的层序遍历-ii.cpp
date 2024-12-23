/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> layer;
        vector<vector<int>> results;
        order(results, 0, root);
        reverse(results.begin(), results.end());        
        return results;
    }
};
// @lc code=end

