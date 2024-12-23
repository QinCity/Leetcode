/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> layer;
        vector<int> result;
        if (root != NULL) {
            layer.push(root);
        }
        while (!layer.empty()) {
            int layer_size = layer.size();
            int max_val;
            for (int i = 0; i < layer_size; i++) {
                TreeNode* cur = layer.front();
                layer.pop();
                if (i == 0) {
                    max_val = cur->val;
                }
                else {
                    max_val = max(max_val, cur->val);
                }
                if (cur->left != NULL)
                    layer.push(cur->left);
                if (cur->right != NULL) 
                    layer.push(cur->right);
            }
            result.push_back(max_val);
        }
        return result; 
    }
};
// @lc code=end

