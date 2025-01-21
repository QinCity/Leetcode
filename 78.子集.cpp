/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> cur_part;
public:
    void traverse(vector<int> &nums, int begin) {
        result.push_back(cur_part);
        if (begin == nums.size())
            return;
        for (int i = begin; i < nums.size(); i++) {
            cur_part.push_back(nums[i]);
            traverse(nums, i + 1);
            cur_part.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        traverse(nums, 0);
        return result;
    }
};
// @lc code=end

