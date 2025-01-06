/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int nums_size = nums.size();
        vector<TreeNode*> tree(nums_size);
        vector<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.back()]) {
                tree[i]->left = tree[stk.back()];
                stk.pop_back();
            }
            if (!stk.empty()) {
                tree[stk.back()]->right = tree[i];
            }
            stk.push_back(i);
        }
        // TreeNode* root = nullptr;
        // for (int i = 0; i < nums_size; i++) {
        //     if (left[i] == -1 && right[i] == -1)
        //         root = tree[i];
        //     else if (right[i] == -1 || (left[i] != -1 && nums[left[i]] < nums[right[i]])) {
        //         tree[left[i]]->right = tree[i];
        //     } 
        //     else {
        //         tree[right[i]]->left = tree[i];
        //     }
        // } 
        return tree[stk[0]]; 
    }
};
// @lc code=end

//法一：暴力法
    // int maxNum(int left, int right, vector<int>& nums) {
    //     int max_num = nums[left];
    //     int num = left;
    //     for (int i = left; i <= right; i++)
    //         if (max_num < nums[i]) {
    //             max_num = nums[i];
    //             num = i;
    //         }
    //     return num;
    // }
    // TreeNode* consTree(int left, int right, vector<int>& nums) {
    //     if (left > right)
    //         return nullptr;
    //     int mid_num = maxNum(left, right, nums);
    //     int pre_num = nums[mid_num];
    //     TreeNode* cur = new TreeNode(pre_num);
    //     cur->right = consTree(mid_num + 1, right, nums);
    //     // cout <<"right end" <<endl;
    //     cur->left = consTree(left, mid_num - 1, nums);
    //     // cout <<"left end" <<endl;
    //     return cur;
    // }
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     return consTree(0, nums.size() - 1, nums);    
    // }

//法二：单调栈
        // int nums_size = nums.size();
        // vector<int> left(nums_size, -1);
        // vector<int> right(nums_size, -1);
        // stack<int> stk;
        // vector<TreeNode*> tree(nums_size);
        // for (int i = 0; i < nums.size(); i++) {
        //     tree[i] = new TreeNode(nums[i]);
        //     while (!stk.empty() && nums[i] > nums[stk.top()]) {
        //         right[stk.top()] = i;
        //         stk.pop();
        //     }
        //     if (!stk.empty()) {
        //         left[i] = stk.top();
        //     }
        //     stk.push(i);
        // }
        // TreeNode* root = nullptr;
        // for (int i = 0; i < nums_size; i++) {
        //     if (left[i] == -1 && right[i] == -1)
        //         root = tree[i];
        //     else if (right[i] == -1 || (left[i] != -1 && nums[left[i]] < nums[right[i]])) {
        //         tree[left[i]]->right = tree[i];
        //     } 
        //     else {
        //         tree[right[i]]->left = tree[i];
        //     }
        // } 
        // return root; 