/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < nums[i])
                sum = nums[i];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
// @lc code=end

