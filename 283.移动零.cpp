/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num = nums.size();
        int front = 0, back = 0;
        while (back < num) {
            if (nums[back] != 0) {
                swap(nums[back], nums[front]);
                front++;
            }
            back++;
        }
    }
};
// @lc code=end



//---------------法一：从前往后双指针--------------
        // int num = nums.size();
        // int front = 0, back = 0;
        // while (back < num) {
        //     while (front < num && nums[front] != 0) {
        //         front++;
        //         back = front + 1;
        //     }
        //     if (back < num && nums[back] != 0) {
        //         nums[front] = nums[back];
        //         nums[back] = 0;
        //     }
        //     back++;
        // }

