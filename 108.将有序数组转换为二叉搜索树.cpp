/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* addLeave(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = addLeave(nums, left, mid - 1);
        cur->right =  addLeave(nums, mid + 1, right);
        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int nums_size = nums.size();
        TreeNode* root = addLeave(nums, 0, nums_size - 1);
        return root;
    
    }
};
// @lc code=end

