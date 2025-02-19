/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) { // 这里uint64_t也可以
        int len_s = s.size(), len_t = t.size();
        vector<vector<unsigned long long>> dp(len_t, vector<unsigned long long>(len_s));    // 以i，j为结尾的出现的次数
        dp[0][0] = s[0] == t[0] ? 1 : 0;
        for (int i = 1; i < len_s; ++i) {
            if (t[0] == s[i]) {
                dp[0][i] = dp[0][i - 1] + 1;
            }
            else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < len_t; ++i) {
            for (int j = i; j < len_s; ++j) {
                if (s[j] == t[i]) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]);
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[len_t - 1][len_s - 1];
    }
};
// @lc code=end

