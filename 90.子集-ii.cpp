/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> frequence;
    vector<vector<int>> result;
    vector<int> cur_part;
public:
    void traverse(int begin) {
        result.push_back(cur_part);
        if (begin == frequence.size())
            return;
        for (int i = begin; i < frequence.size(); i++) {
            for (int j = 1; j <= frequence[i].second; j++) {
                cur_part.push_back(frequence[i].first);
                traverse(i + 1);
            }
            for (int j = 1; j <= frequence[i].second; j++) {
                cur_part.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto num: nums) {
            if (frequence.empty() || frequence.back().first != num)
                frequence.emplace_back(num, 1);
            else 
                frequence.back().second++;
        }
        traverse(0);
        return result;           
    }
};
// @lc code=end

