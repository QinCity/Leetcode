/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int sum = 0; 
        int M;
        for (auto &num: nums) {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;
        M = sum / 2 + 1;
        vector<vector<int>> dp(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < M; i++) {
            if (nums[0] <= dp[0][i])
                dp[0][i] = nums[0];
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (j - nums[i] >= 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[N - 1][M - 1] == M - 1)
            return true;
        return false;
    }
};
// @lc code=end

