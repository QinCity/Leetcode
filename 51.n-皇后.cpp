/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
    vector<bool> can_x, can_z1, can_z2;
    vector<int> result;
    vector<vector<string>> ans;
public:
    void getAns() {
        vector<string> tmp_part;
        for(int i = 0; i < result.size(); i++) {
            string tmp;
            for(int j = 0; j < result.size(); j++) {
                if (j != result[i]) {
                    tmp += '.';   
                }
                else {
                    tmp += 'Q';
                }
            }
            tmp_part.push_back(tmp);
        }
        ans.push_back(tmp_part);
    }
    void traverse(int num, int n) {

        if (num == n) {
            getAns();
            return;
        }
        for (int i = 0; i < n; i++) {
            if (can_x[i] == 0 && can_z1[i - num + n - 1] == 0 && can_z2[i + num + n -1] == 0) {
                can_x[i] = 1;
                can_z1[i - num + n - 1] = 1;
                can_z2[i + num + n - 1] = 1;
                result.push_back(i);
                traverse(num + 1, n);
                can_x[i] = 0;
                can_z1[i - num + n - 1] = 0;
                can_z2[i + num + n - 1] = 0;
                result.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        can_x.resize(n);
        can_z1.resize(3 * n);
        can_z2.resize(3 * n);
        traverse(0, n);
        return ans;
    }
};
// @lc code=end

