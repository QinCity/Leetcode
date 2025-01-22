/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
 
    void traverse(int pos, vector<bool> &used, vector<int> &nums, vector<int> &cur_part, int begin) {
        if (pos > nums.size())
            return;
        if (pos == nums.size()) {
            result.push_back(cur_part);
            return;
        }
        if (pos > 0 && nums[pos] != nums[pos - 1])
            begin = 0;
        for (int i = begin; i < nums.size(); i++) {
            if (used[i] == 0) {
                used[i] = 1;
                cur_part[i] = nums[pos];
                traverse(pos + 1, used, nums, cur_part, i + 1);
                used[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<bool> used(size);
        vector<int> cur_part(size);
        traverse(0, used, nums, cur_part, 0);
        return result;
    }
};
// @lc code=end

