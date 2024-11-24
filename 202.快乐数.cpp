/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> exist;
        int current_num = n;
        while (exist.count(current_num) != 1) {
            exist.insert(current_num);
            if (current_num == 1)
                return true;
            current_num = calHappyNum(current_num);
        }
        return false;
    }


    int calHappyNum(int num) {
        int sum = 0;
        while (num != 0) {
            int tmp = num % 10;
            sum += tmp * tmp;
            num = num / 10;
        }
        return sum;
    }
};
// @lc code=end

