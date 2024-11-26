/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int left, right;
        for (int i = 0; i < nums.size() - 2;) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1] ) {
                        right--;
                    }
                    right--;    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) { // 这里可以不用判断，不过也无所谓
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                }
                else {
                    while (left < right &&nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;    
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
            i++;
        }
        return result;
    }
};
// @lc code=end

