/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        int length = m * n;
        vector<int> result(length);
        int number = 0;
        int left = 0, right = m - 1, up = 0, down = n - 1;
        while (number < length) {
            for (int i = left; i <= right; i++) {
                result[number++] = matrix[up][i];
            }
            if (number == length) {
                break;
            }
            up++;
            for (int i = up; i <= down; i++) {
                result[number++] = matrix[i][right];
            }
            if (number == length) {
                break;
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[number++] = matrix[down][i];
            }
            if (number == length) {
                break;
            }
            down--;
            for (int i = down; i >= up; i--) {
                result[number++] = matrix[i][left];
            }
            left++;
        }
        return result; 
    }
};
// @lc code=end

