/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        int result = 0;
        vector<int> right(N, -1), left(N, -1);
        stack<int> s,t;
        for (int i = 0 ; i < N; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int cur = s.top();
                s.pop();
                right[cur] = i;
            }
            left[i] = s.empty() ? -1 : s.top(); 
            s.push(i);
        }
        // for (int i = N - 1; i >= 0; i--) {
        //     while (!t.empty() && heights[t.top()] > heights[i]) {
        //         int cur = t.top();
        //         t.pop();
        //         left[cur] = i;
        //     }
        //     t.push(i);
        // }
        for (int i = 0; i < N; i++) {
            if (right[i] == -1)
                right[i] = N;
            if (left[i] == -1)
                left[i] = -1;
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        }
        return result;
    }
};
// @lc code=end

