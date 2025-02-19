/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.size(), len_2 = word2.size();
        int result = 0;
        vector<vector<int>> dp(len_1 + 1, vector<int>(len_2 + 1));
        for (int i = 1; i <= len_1; i++) {
            for (int j = 1; j <= len_2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return len_1 + len_2 - 2 * dp[len_1][len_2];
    }
};
// @lc code=end

