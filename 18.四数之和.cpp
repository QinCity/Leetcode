/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int k = j + 1; k < n - 1; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue;
                    int four = k + 1;
                    double sum = 0;
                    while (four < n) {
                        sum = 0.0 +nums[i] + nums[j] + nums[k] + nums[four];
                        if (sum < target)
                            four++;
                        else
                        {
                            break;
                        }
                        
                    }
                    if (four < n){
                        sum = 0.0+ nums[i] + nums[j] + nums[k] + nums[four];
                        if (sum == target)
                            result.push_back({nums[i], nums[j], nums[k], nums[four]});
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

