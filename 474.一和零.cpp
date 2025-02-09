/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 0; i < N; i++) {
            int num0 = 0, num1 = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    num0++;
                else {
                    num1++;
                }
            }
            if (i == 0) {
                for (int j = num0; j <= m; j++) {
                    for (int k = num1; k <= n; k++) {
                        dp[i][j][k] = 1;
                    }
                }
            }
            else {
                for (int j = 0; j <= m; j++) {
                    for (int k = 0; k <= n; k++) {
                        if (j - num0 < 0 || k - num1 < 0)
                            dp[i][j][k] = dp[i - 1][j][k];
                        else
                            dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - num0][k - num1] + 1);
                    }
                }
            }
            
        
        }
        return dp[N - 1][m][n];
    }
};
// @lc code=end

