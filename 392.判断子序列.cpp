/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size(), len_t = t.size();
        if (len_s > len_t)
            return false;
        int j = -1;
        for (int i = 0; i < len_s; ++i) {
            for (++j; j < len_t; ++j) {
                if (s[i] == t[j]) {
                    break;
                }
            }
            if (j == len_t)
                return false;
        }
        return true;
    }
};
// @lc code=end

