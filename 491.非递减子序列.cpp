/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
    vector<vector<int>> result;
    vector<int> cur_part;
    void traverse(int begin, vector<int>& nums) {
        if (cur_part.size() >= 2)
            result.push_back(cur_part);
        if (begin == nums.size())
            return;
        unordered_map<int, int> used;
        int last = -1;
        for(int i = begin; i < nums.size(); i++) {
                if ((cur_part.empty() || cur_part.back() <= nums[i]) && used.find(nums[i]) == used.end()) {
                    cur_part.push_back(nums[i]);
                    traverse(i + 1, nums);
                    cur_part.pop_back();
                    used[nums[i]] = 1;
                }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        traverse(0, nums);
        return result;
    }
};
// class Solution {
//     vector<vector<int>> result;
//     vector<int> cur_part;

//     void traverse(int begin, vector<int>& nums) {
//         if (cur_part.size() >= 2) {
//             result.push_back(cur_part);
//         }

//         // 从当前索引开始递归，避免重复
//         unordered_set<int> used;
//         for (int i = begin; i < nums.size(); i++) {
//             // 只有当当前数字大于或等于上一个数字时才继续递归
//             if (cur_part.empty() || cur_part.back() <= nums[i]) {
//                 // 避免当前层次的重复
//                 if (used.find(nums[i]) == used.end()) {
//                     cur_part.push_back(nums[i]);
//                     traverse(i + 1, nums);
//                     cur_part.pop_back();
//                     used.insert(nums[i]); // 标记当前数字为已使用
//                 }
//             }
//         }
//     }

// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         traverse(0, nums);
//         return result;
//     }
// };
// @lc code=end

