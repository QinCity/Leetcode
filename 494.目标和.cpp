/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());

        int sum = 0;
        int N = nums.size();
        int M;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum - target < 0 || (sum - target) % 2 != 0 )
            return 0;
        M = (sum - target) / 2;

        vector<vector<int>> dp(N, vector<int>(M + 1));

        dp[0][0] = 1;
        if (nums[0] <= M)
            dp[0][nums[0]] += 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= M; j++) {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N - 1][M];
    }
};
// @lc code=end

