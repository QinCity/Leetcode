/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2));
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int i = 1; i < len1; i++) {
            dp[i][0] = max(text1[i] == text2[0] ? 1 : 0, dp[i - 1][0]);
        }
        for (int i = 1; i < len2; i++) {
            dp[0][i] = max(text1[0] == text2[i] ? 1 : 0, dp[0][i - 1]);
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};
// @lc code=end

