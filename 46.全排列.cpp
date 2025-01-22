/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> cur_part;
    void traverse(int pos, vector<bool> &used, vector<int> &nums) {
        if (pos == nums.size()) {
            result.push_back(cur_part);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 0) {
                used[i] = 1;
                cur_part.push_back(nums[i]);
                traverse(pos + 1, used, nums);
                cur_part.pop_back();
                used[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<bool> used(size);
        traverse(0, used, nums);
        return result;
    }
};
// @lc code=end

