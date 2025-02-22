/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        stack<int> s;
        vector<int> result(N, -1);
        for (int i = 0; i < 2 * N; i++) {
            while (!s.empty() && nums[i % N] > nums[s.top()]) {
                int t = s.top();
                s.pop();
                result[t] = nums[i % N];
            }
            s.push(i % N);
            
        }
        return result;
    }
};
// @lc code=end

