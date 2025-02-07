/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1, dp[1] = 1;
        for (int i = 3; i < n + 1; i++) {
            int max_mul = 0;
            for (int j = 1; j <= i / 2; j++) {
                max_mul = max(max_mul, max(dp[j], j) * max(dp[i - j], i - j));
            }
            dp[i] = max_mul;
        }
        return dp[n];
    }
};
// @lc code=end

