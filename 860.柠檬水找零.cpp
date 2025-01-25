/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money[3] = {0, 0, 0};
        int num[3] = {20, 10, 5};
        for (int i = 0; i < bills.size(); i++) {
            int tmp = bills[i];
            for (int j = 0; j < 3; j++) {
                money[j] += tmp / num[j];
                tmp -= tmp / num[j] * num[j];
            }
            bills[i] -= 5;
            for (int j = 0; j < 3; j++) {
                int number = min(bills[i] / num[j], money[j]);
                money[j] -= number;
                bills[i] -= number * num[j];
            }
            if (bills[i] > 0)
                return false;
        } 
        
        return true;
    }
};
// @lc code=end

