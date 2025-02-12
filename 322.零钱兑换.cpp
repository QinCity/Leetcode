/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001); // 达到j金额所需要的最小数量
        int N = coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i >= coins[j] ) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                    // if (i > 3000)
                        // cout << i << " " << dp[i] <<endl;
                }
            }
        }
        if (dp[amount] == 10001)
            return -1;
        else {
            return dp[amount];
        }
    }
};
// @lc code=end

