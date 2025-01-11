/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (!(cur == p || cur == q || (cur->val < p->val && cur->val > q->val) || (cur->val > p->val && cur->val < q->val))) {
            if (cur->val > q->val)
                cur = cur->left;
            else 
                cur = cur->right;
        }
        return cur;
    }
};
// @lc code=end

