/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    void reverse_str(string &s, int left, int right) {
        for (; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }

    string reverseStr(string s, int k) {
        int length = s.size();
        int right = 0;
        while (right < length) {
            if (right + 2 * k < length) {
                reverse_str(s, right, right + k - 1);              
            }
            else if (right + k < length) {
                reverse_str(s, right, right + k - 1);
            }
            else {
                reverse_str(s, right, length - 1);
            }
            right += 2 * k;
        }
        return s;
    }
};
// @lc code=end

