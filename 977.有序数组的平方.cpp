/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int front = 0, back = nums.size() - 1;
        vector<int> result(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[front]) > abs(nums[back])) {
                result[i] = nums[front] * nums[front];
                front++;
            } 
            else {
                result[i] = nums[back] * nums[back];
                back--; 
            }
        }
        return result;
    }
};
// @lc code=end

