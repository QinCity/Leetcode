/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int sum = 0;
        stack<int> right;
        for (int i = 0; i < N; i++) {
            while(!right.empty() && height[right.top()] < height[i]) {
                int cur_pos = right.top();
                right.pop();
                if (!right.empty()) {
                    int h = min(height[right.top()], height[i]) - height[cur_pos];
                    int w = i - right.top() - 1;
                    sum += h * w;
                }
                
            }
            right.push(i);
        }
        return sum;
    }
};
// @lc code=end

