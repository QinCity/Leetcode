/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int number = 1;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        while (number <= n * n) {
            for (int i = left; i <= right; i++) {
                result[up][i] = number++; 
            }
            up++;
            for (int i = up; i <= down; i++) {
                result[i][right] = number++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[down][i] = number++;
            }
            down--;
            for (int i = down; i >= up; i--) {
                result[i][left] = number++;
            }
            left++;
        }
        return result;
    }
};
// @lc code=end

