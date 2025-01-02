/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    bool isLeaf(TreeNode* cur) {
        if (!cur->left && !cur->right)
            return 1;
        return 0;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> order;
        order.push(root);
        while (!order.empty()) {
            TreeNode* cur = order.front();
            order.pop();
            if (cur->left) {
                order.push(cur->left);
                if (isLeaf(cur->left))
                    sum += cur->left->val;
            }
            if (cur->right)
                order.push(cur->right);
        }
        return sum;
    }
};
// @lc code=end

