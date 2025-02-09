/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& stone: stones) {
            sum += stone;
        }
        int N = stones.size();
        int M = sum / 2;
        vector<vector<int>> dp(N, vector<int>(M + 1));
        for (int i = 0; i < N; i++) {
            dp[i][0] = 0;
        }
        for (int i = stones[0]; i <= M; i++) {
            dp[0][i] = stones[0]; 
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= M; j++) {
                if (stones[i] <= j)
                    dp[i][j] = max(dp[i - 1][j - stones[i]] + stones[i], dp[i - 1][j]);
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int i = M; i >= 0; i--) {
            if (dp[N - 1][i] == i)
                return sum - 2 * i;
        } 
        return 0;
    }
};
// @lc code=end

