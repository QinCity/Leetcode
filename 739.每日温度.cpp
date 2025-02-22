/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        int N = temperatures.size();
        vector<int> result(N);
        temp.push(0);
        for (int i = 1; i < N; i++) {
            while (!temp.empty() && temperatures[i] > temperatures[temp.top()]) {
                int t = temp.top();
                temp.pop();
                result[t] = i - t;
            }
            temp.push(i);
        }
        while (!temp.empty()) {    // vector默认是0，这一段可以省略
            int t = temp.top();
                temp.pop();
                result[t] = 0;
        }
        return result;
    }
     
};
// @lc code=end

