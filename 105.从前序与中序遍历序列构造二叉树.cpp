/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
    map<int, int> mid_order;
    int order = 0;
public:
    TreeNode* consTree(int left, int right, vector<int>& preorder) {
        if (left > right)
            return nullptr;
        int pre_num = preorder[order++];
        int mid_num = mid_order[pre_num];
        TreeNode* cur = new TreeNode(pre_num);
        cur->left = consTree(left, mid_num - 1, preorder);
        cur->right = consTree(mid_num + 1, right, preorder);
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mid_order[inorder[i]] = i;
        return consTree(0, inorder.size() - 1, preorder);    
    }
};
// @lc code=end

