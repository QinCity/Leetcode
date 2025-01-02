/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traverseTree(TreeNode* cur, vector<string> &result, string cur_road) {
        cur_road += ("->" + to_string(cur->val));
        if (!cur->left && !cur->right) {
            result.push_back(cur_road);
            return;
        }
        if (cur->left)
            traverseTree(cur->left, result, cur_road);
        if (cur->right)
            traverseTree(cur->right, result, cur_road);

    } 


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string road = to_string(root->val);
        if (!root->left && !root->right)
            result.push_back(road);
        if (root->left)
            traverseTree(root->left, result, road);
        if (root->right)
            traverseTree(root->right, result, road);
        return result;
    }
};
// @lc code=end

