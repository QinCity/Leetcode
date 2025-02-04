/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
private:
    int num = 0;
public:
    int dfs(TreeNode* root) { // 0:表示未被监视， 1:表示被监视，2:表示放置监视
        if (!root) {
            return 1;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == 0 || right == 0) {
            num++;
            return 2;
        }
        else if (left == 2 || right == 2) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) {
            num++;
        }
        return num;
    }
};
// @lc code=end

