/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> order;
        int left_most = root->val;
        order.push(root);
        while (!order.empty()) {
            int layer_size = order.size();
            left_most = order.front()->val;
            for (int i = 0; i < layer_size; i++) {
                TreeNode* cur = order.front();
                order.pop();
                if (cur->left)
                    order.push(cur->left);
                if (cur->right)
                    order.push(cur->right); 
            }
        }
        return left_most;    
    }
};
// @lc code=end

