/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:

    int monotoneIncreasingDigits(int n) {
        vector<int> num;
        int result = 0;
        while (n != 0) {
            num.push_back(n % 10);
            n /= 10;
        }
        int len = num.size();
        for (int i = len - 1; i >= 1; i--) {
            if (num[i] > num[i - 1]) {
                for (int j = len - 1; j >= i; j--) {
                    if (num[j] == num[i]) {
                        i = j; 
                        break;
                    }
                }
                num[i]--;
                i--;
                while (i >= 0) {
                    num[i] = 9;
                    i--;
                }
                break;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            result *= 10;
            result += num[i];
        }
        return result;

    }
};
// @lc code=end

