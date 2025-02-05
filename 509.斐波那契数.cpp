/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int n1 = 1, n2 = 0, result;
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        --n;
        while (n > 0) {
            result = n1 + n2;
            n2 = n1;
            n1 = result;
            --n;
        }
        return result;
    }
};
// @lc code=end

