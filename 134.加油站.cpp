/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> consume(gas.size());
        int all_cost = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            consume[i] = gas[i] - cost[i];
            all_cost += consume[i];
        }
        if (all_cost < 0)
            return -1;
        for (int i = 0; i < gas.size(); i++) {
            if (sum < 0 && consume[i] > 0) {
                start = i;
                sum = 0;
            }
                
            sum += consume[i];
        }
        return start;
    }
};
// @lc code=end

