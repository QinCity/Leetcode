/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = nums.size();
        int front = 1, back = 1;
        while (back < num) {
            if (nums[back] != nums[front - 1]) {
                nums[front] = nums[back];
                front++;
            }
            back++;
        }
        return front;
    }
};
// @lc code=end

