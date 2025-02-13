/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N);
        if (N <= 1) {
            return nums[0];
        }
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == 1) {
                dp[i] = nums[i];
            }
            else if (i == 2) {
                dp[i] = nums[i] + nums[0];
            }
            else {
                dp[i] = max(dp[i - 3] + nums[i], dp[i - 2] + nums[i]);
            }
        }
        return max(dp[N - 1] , dp[N - 2]);
    }
};
// @lc code=end

