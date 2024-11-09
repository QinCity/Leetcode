/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int basket[2][2] = {{-1, -1}, {-1, -1}};
        int sum = 0;
        int max = 0;
        for (int i = 0; i < fruits.size(); i++) {
            if (fruits[i] == basket[0][0]) {
                basket[1][0] = i;
                sum++;
            }
            else if (fruits[i] == basket[0][1]) {
                basket[1][1] = i;
                sum++;
            }
            else {
                if (sum > max) {
                    max = sum;
                }
                if (basket[1][0] <= basket[1][1]) {
                    sum = i - basket[1][0];
                    basket[0][0] = fruits[i];
                    basket[1][0] = i;
                }
                else {
                    sum = i - basket[1][1];
                    basket[0][1] = fruits[i];
                    basket[1][1] = i;
                }
            }
        }
        if (sum > max) {
            max = sum;
        }
        return max;
    }
};
// @lc code=end

