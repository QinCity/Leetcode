/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n));
        dp[0][0] = - prices[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[2][i - 1]);
            dp[2][i] = dp[0][i - 1] + prices[i];
        }
        return max(dp[2][n - 1], dp[1][n - 1]);
    }
};
// @lc code=end

