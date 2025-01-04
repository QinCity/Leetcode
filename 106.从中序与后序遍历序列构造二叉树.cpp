/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    map<int, int> order_map;
    int post;

public:
    TreeNode* cons_tree(int left, int right, vector<int>& postorder)  { // 中序遍历的区间，这里记得先计算右子树，再看左子树，因为post是共有变量，所以要按顺序来，先是右子树的根，再是左子树的。如果分别在函数里统计左右子树的区间，就不需要区别顺序。
        if (left > right)
            return nullptr;
        int post_number = postorder[post--];
        int order_num = order_map[post_number];
        TreeNode* cur = new TreeNode(post_number);
        cur->right = cons_tree(order_num + 1, right, postorder);
        cur->left = cons_tree(left, order_num - 1, postorder);
        return cur;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            order_map[inorder[i]] = i;
        }
        post = postorder.size() - 1;
        TreeNode* root = cons_tree(0, inorder.size() - 1, postorder);
        return root;        
        
    }
};
// @lc code=end

