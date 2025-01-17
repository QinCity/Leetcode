/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<int> current_combin;
public:
    void reverse(vector<vector<int>> &result,  int remain, int n) {
        if (remain <= 0) {
            result.push_back(current_combin);
            return;
        }
        int num;
        if (!current_combin.empty())
            num = current_combin.back();
        else 
            num = 0;
        for (int i = num + 1; i <= n; i++){
            current_combin.push_back(i);
            reverse(result,  remain - 1, n);
            current_combin.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current_combin;
        reverse(result, k, n);
        return result;
    }
};
// @lc code=end

