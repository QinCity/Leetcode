/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
// class Solution {
// private:
//     int sum = 0;
// public:
//     TreeNode* buildLeave(TreeNode* root) {
//         if (!root)
//             return nullptr;
//         TreeNode* cur = new TreeNode();
//         cur->right = buildLeave(root->right);
//         sum += root->val;
//         cur->val = sum;
//         cur->left = buildLeave(root->left);
//         return cur;
//     }

//     TreeNode* convertBST(TreeNode* root) {
//         return buildLeave(root);
//     }
// };
class Solution {
public:
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

// @lc code=end

