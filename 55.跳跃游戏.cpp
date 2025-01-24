/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_distance = 0;
        int nums_size = nums.size();
        for (int i = 0; i <= min(max_distance, nums_size - 1); i++) {
            max_distance = max(max_distance, nums[i] + i);
        }
        if (max_distance >= nums_size - 1)
            return true;
        else
            return false;
    }
};
// @lc code=end

