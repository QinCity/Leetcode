/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int> > v_fre(freq.begin(), freq.end());
        sort(v_fre.begin(), v_fre.end(), cmp);
        for (int i = 0; i < k; i++) 
            result.push_back(v_fre[i].first);
        return result;
    }
};
// @lc code=end

