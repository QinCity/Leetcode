/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(4, vector<int>(N));
        // 初始化
        dp[0][0] = - prices[0];
        dp[1][0] = 0;
        dp[2][0] = - prices[0];
        dp[3][0] = 0;
        // dp
        for (int i = 1; i < N; i++) {
            dp[0][i] = max( - prices[i], dp[0][i - 1]);
            dp[1][i] = max(dp[0][i - 1] + prices[i], dp[1][i - 1]);
            dp[2][i] = max(dp[1][i - 1] - prices[i], dp[2][i - 1]);
            dp[3][i] = max(dp[2][i - 1] + prices[i], dp[3][i - 1]); 
        }
        return dp[3][N - 1];
    }
};
// @lc code=end

