/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    }
};
// @lc code=end



//---------------法1:快慢指针 O(n)---------------
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     int min = 1000000;
    //     int sum = 0;
    //     int left = 0, right = 0;
    //     for (int right = 0; right < nums.size(); right++) {
    //         sum += nums[right];
    //         while (sum >= target) {
    //             if (right - left + 1 < min) {
    //                 min = right - left + 1;       
    //             }
    //             sum -= nums[left++];
    //         }
    //     }
    //     if (min == 1000000)
    //         return 0;
    //     else
    //         return min;
    // }


//--------------法2: O(nlog(n))----------
    // 这里只提供思路，对于数组里的每个数，选中他之后，对与他前面那一部分的数用二分法找到最小的大于target的数组