/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exist;
        vector<int> result;
        int num = 0;
        for (int& i:nums) {
            if (exist.count(target - i) == 1) {
                result.push_back(num);
                result.push_back(exist[target - i]);
                return result;

            }
            exist[i] = num++; 
        } 
        return result;
    }
};
// @lc code=end

