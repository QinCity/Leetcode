/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int num = 1;
        int sub = 0;
        if (nums.size() < 2)
            return nums.size();
        int start = 1;
        sub = nums[start] - nums[start - 1];
        while (sub == 0 && start < nums.size()) {
            sub = nums[start] - nums[start - 1];
            start++;
        }
        if (start == nums.size())
            return 1;
        for (int i = start; i < nums.size(); i++) {
            int tmp = nums[i] - nums[i - 1];
            if (tmp * sub < 0) {
                sub = tmp;
                num++;
            }
        }
        return (num + 1) ;
    }
};
// @lc code=end

