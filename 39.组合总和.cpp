/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<int> current_result;
    vector<vector<int>> result;
    void traverse(int pos, int remaining, vector<int> &candidates) {
        if (remaining == 0) {
            result.push_back(current_result);
            return;
        }
        if (pos >= candidates.size() || remaining < candidates[pos])
            return;
        int num = remaining / candidates[pos];
        traverse(pos + 1, remaining, candidates);
        for (int i = 0; i < num; i++) {
            current_result.push_back(candidates[pos]);
            remaining -= candidates[pos];
            traverse(pos + 1, remaining, candidates);
        }
        for (int i = 0; i < num; i++) {
            current_result.pop_back();
            remaining += candidates[pos];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target < 2)
            return result;
        sort(candidates.begin(), candidates.end());
        traverse(0, target, candidates);
        return result;
        
    }
};
// @lc code=end

