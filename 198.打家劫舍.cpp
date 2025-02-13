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
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == 1) {
                dp[i] = nums[i];
            }
            else if (i == 2) {
                dp[i] = nums[i] + nums[0];
            }
            else {
                dp[i] = max(nums[i], nums[i]);
            }
        }
    }
};
// @lc code=end

