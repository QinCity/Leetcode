/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<int> current_combin;
public:
    void reverse(vector<vector<int>> &result,  int remain_time, int n, int remain_sum) {
        if (remain_time == 0 && remain_sum == 0) {
            result.push_back(current_combin);
            return;
        }
        if (remain_sum <= 0 || remain_time == 0)
            return;
        int num;
        if (!current_combin.empty())
            num = current_combin.back();
        else 
            num = 0;
        for (int i = num + 1; i <= n; i++){
            current_combin.push_back(i);
            reverse(result, remain_time - 1, n, remain_sum - i);
            current_combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        reverse(result, k, 9, n);
        return result;
    }
};
// @lc code=end

