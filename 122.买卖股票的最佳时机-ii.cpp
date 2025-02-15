/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i] );
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
        }
        return dp[1][N - 1];
    }
};
// @lc code=end

// 法1
int sum = 0;
// for (int i = 0; i < prices.size() - 1; i++) {
//     if (prices[i + 1] - prices[i] > 0) {
//         sum += prices[i + 1] - prices[i];
//     }
// }
// return sum;