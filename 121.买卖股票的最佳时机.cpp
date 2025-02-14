/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(2, vector<int>(N));
        dp[0][0] = - prices[0];
        dp[1][0] = 0; 
        for (int i = 1; i < N; i++) {
            dp[0][i] = max(-prices[i], dp[0][i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
        }
        return dp[1][N - 1];
    }
};
// @lc code=end

