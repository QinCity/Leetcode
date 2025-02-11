/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();

        vector<vector<uint64_t>> dp(N, vector<uint64_t>(amount + 1));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
               dp[0][i] = 1;
        }
        for (int i = 0; i < N; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i] >= 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
                
            }
        }
        return dp[N - 1][amount];
    }
};
// @lc code=end

