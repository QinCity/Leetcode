/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1, right = num, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid == num)
                return 1;
            else if (mid * mid > num) {
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        return 0;
        
    }
};
// @lc code=end

