/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        int result = -10001;
        vector<int> dp(N);
        dp[0] = nums[0];
        result = nums[0];
        for (int i = 1; i < N; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }
};
// @lc code=end

// 法1
// int max_sum = nums[0];
// int sum = 0;
// for (int i = 0; i < nums.size(); i++) {
//     sum += nums[i];
//     if (sum < nums[i])
//         sum = nums[i];
//     if (sum > max_sum) {
//         max_sum = sum;
//     }
// }
// return max_sum;