/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
            else {
                if (i > 1) {
                    if (nums[i] > nums[i - 1]) {
                        nums[i - 1] = k % 2? -nums[i - 1] : nums[i - 1];
                    }
                    else {
                        nums[i] = k % 2? -nums[i] : nums[i];
                    }
                }
                else {
                   nums[i] = k % 2? -nums[i] : nums[i]; 
                }
                k = 0;
                break;
            }
        }
        if (k > 0)
            nums[nums.size() - 1] = k % 2? -nums[nums.size() - 1] : nums[nums.size() - 1]; 
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        return sum;
    }
};
// @lc code=end

