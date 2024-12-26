/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isS(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2)
            return true;
        if (!node1 || !node2)
            return false;
        if (node1->val != node2->val)
            return false;
        if (isS(node1->left, node2->right) && isS(node1->right, node2->left))
            return true;
        return false;  
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isS(root->left, root->right);
    }

};
// @lc code=end

