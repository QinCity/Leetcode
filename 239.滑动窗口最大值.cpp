/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> stor;
        vector<int> result;
        for (int i = 1; i <= k; i++) {
            stor.emplace(nums[i - 1], i - 1);
        }
        result.push_back(stor.top().first);
        for (int i = k; i < nums.size(); i++) {
            stor.emplace(nums[i], i);
            while (stor.top().second < i - k + 1) {
                stor.pop();
            }
            result.push_back(stor.top().first);
        }
        return result;
    }
};
// @lc code=end

