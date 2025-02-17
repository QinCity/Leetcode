/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(2 * k);
        int N = prices.size();
        for (int i = 0; i < k; ++i) {
            dp[2 * i] = - prices[0];
        }
        for (int i = 0; i < N; i++) {
            dp[0] = max(-prices[i], dp[0]);
            for (int j = 1; j < 2 * k; j++) {
                if (j % 2 == 1) {
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                }
            }
        }
        return dp[2 * k - 1];
    }
};
// @lc code=end

