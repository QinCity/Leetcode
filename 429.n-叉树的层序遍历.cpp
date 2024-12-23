/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> layer;
        vector<vector<int>> results;
        if (root != NULL) {
            layer.push(root);
        }
        while (!layer.empty()) {
            int layer_size = layer.size();
            vector<int> result;
            for (int i = 0; i < layer_size; i++) {
                Node* cur = layer.front();
                layer.pop();
                result.push_back(cur->val);
                for (auto child:cur->children) {
                    layer.push(child);
                }
            }
            results.push_back(result);
        }
        return results; 
    }
};
// @lc code=end

