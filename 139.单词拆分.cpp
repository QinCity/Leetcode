/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public: 
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<bool> dp(N + 1, 0); // 从开头开始数到当前字符是否出现
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                int M = wordDict[j].size();
                if (i - M >= 0) {
                    if (dp[i - M] == 1 && s.compare(i - M, M, wordDict[j]) == 0) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[N];
    }
};
// @lc code=end

