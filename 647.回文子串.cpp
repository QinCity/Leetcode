/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                if (s[j] == s[j + i]) {
                    if (i >= 2 && dp[j + 1][j + i - 1] != 1) {
                        dp[j][j + i] = 0;
                    } else {
                        dp[j][j + i] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i ; j < N; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
// @lc code=end

