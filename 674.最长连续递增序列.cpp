/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int N = nums.size();
        int max_len = 0, cur_len = 1;
        for (int i = 1; i < N; i++) {
            if (nums[i] <= nums[i - 1]) {
                max_len = max(max_len, cur_len);
                cur_len = 1;
            }
            else {
                cur_len++;
            }
        }
        max_len = max(max_len, cur_len);
        return max_len;
    }
};
// @lc code=end

