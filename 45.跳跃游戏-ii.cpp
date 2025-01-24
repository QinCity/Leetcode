/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int old_max_distance = 0;
        int next_max_distance = 0;
        int times = 0;
        int nums_size = nums.size();
        for (int i = 0; old_max_distance < nums_size - 1; i++) {
            next_max_distance = max(next_max_distance, nums[i] + i);
            if (i == old_max_distance) {
                times++;
                old_max_distance = next_max_distance;
            }
        }
        return times;
    }
};
// @lc code=end

