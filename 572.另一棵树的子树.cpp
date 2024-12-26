/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
        if (isS(node1->right, node2->right) && isS(node1->left, node2->left))
            return true;
        return false;  
    }

    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> order;
        order.push(root);
        while (!order.empty()) {
            TreeNode* cur = order.front();
            order.pop();
            if (cur->val == subRoot->val && isS(cur, subRoot))
                return true;
            if (cur->left)
                order.push(cur->left);
            if (cur->right)
                order.push(cur->right);
        }
        return false;
    }
};
// @lc code=end

