/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        un
        unordered_map<int, vector<int>> num;

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                num[nums[i] + nums[j]].push_back(i);
                num[nums[i] + nums[j]].push_back(j);
            }
            for (int i = 0; i < nums.size(); i++) {
                if (num.count(-nums[i]) == 1) {
                    for (int j = 0; j < num.size(); j+=2) {
                        if (i != num[-nums[i]][j] && num[-nums[i]][j + 1] != i) {
                            result.push_back({num[-nums[i]][j], num[-nums[i]][j + 1]});
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

