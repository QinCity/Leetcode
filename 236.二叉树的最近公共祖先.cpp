/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) {
            return false;
        }
        path.push_back(root);
        if (root == target) {
            return true;
        }
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        
        TreeNode* lca = nullptr;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] == path_q[i]) {
                lca = path_p[i];
            } else {
                break;
            }
        }
        return lca;
    }
};
// @lc code=end

