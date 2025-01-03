/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void deep_reverse(TreeNode* cur, vector<vector<int>> &result, vector<int> cur_str, int sum) {
        cur_str.push_back(cur->val);
        sum -= cur->val;
        if (!cur->left && !cur->right) {
            if (sum == 0)
                result.push_back(cur_str);
        }
        else {
            if (cur->left)
                deep_reverse(cur->left, result, cur_str, sum);
            if (cur->right)
                deep_reverse(cur->right, result, cur_str, sum); 
        }
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> cur_str;
        if (!root)
            return result;
        deep_reverse(root, result, cur_str, targetSum);
        return result;            
    }
};
// @lc code=end

