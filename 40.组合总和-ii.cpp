/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
        vector<int> current_result;
    vector<vector<int>> result;
    vector<pair<int, int> > candidate;
    void traverse(int pos, int remaining) {
        if (remaining == 0) {
            result.push_back(current_result);
            return;
        }
        if (pos >= candidate.size() || remaining < candidate[pos].first)
            return;
        int num = min(remaining / candidate[pos].first, candidate[pos].second);
        traverse(pos + 1, remaining);
        for (int i = 0; i < num; i++) {
            current_result.push_back(candidate[pos].first);
            // remaining -= candidate[pos].first;
            traverse(pos + 1, remaining - (i + 1) * candidate[pos].first);
        }
        for (int i = 0; i < num; i++) {
            current_result.pop_back();
            // remaining += candidate[pos].first;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (target <1)
            return result;
        sort(candidates.begin(), candidates.end());
            for (int num : candidates) {
        if (candidate.empty() || candidate.back().first != num) {
            candidate.emplace_back(num, 1);
        } else {
            candidate.back().second++;
        }
    }
        traverse(0, target);
        return result;
        
    }
};
// @lc code=end

