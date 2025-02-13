/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N);
        vector<bool> steal_1(N);
        if (N <= 1) {
            return nums[N - 1];
        }
        steal_1[0] = 1;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                dp[i] = nums[i];
            }
            else if (i == 1) {
                if (nums[i] >= nums[i - 1]) {
                    dp[i] = nums[i];
                }
                else {
                    dp[i] = nums[i - 1];
                    steal_1[i] = 1;
                }
            }
            else if (i != N - 1){
                if (nums[i] + dp[i - 2] > dp[i - 1]) {
                    dp[i] = nums[i] + dp[i - 2];
                    steal_1[i] = steal_1[i - 2];
                }
                else if (nums[i] + dp[i - 2] == dp[i - 1]) {
                    dp[i] = dp[i - 1];
                    steal_1[i] = steal_1[i - 2] & steal_1[i -1];
                }
                else {
                    dp[i] = dp[i - 1];
                    steal_1[i] = steal_1[i - 1];
                }
            }
            else {
                if (steal_1[i - 2] == 1) {
                    dp[N - 1] = max(dp[i - 1], max(dp[i - 2], dp[i - 2] - nums[0] + nums[N - 1]));
                }
                else {
                    dp[N - 1] = max(dp[i -1], dp[i - 2] + nums[N - 1]);
                }
            }    
             cout << dp[i] << endl;
        }
        return dp[N - 1];
    }
};
// @lc code=end

