/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    void get_next(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        } 
    }
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        vector<int> next(size);
        get_next(&next[0], s);
        int i = s.size() - 1;
        if (next[i] == -1) {
            return false;
        }
        int length = i - next[i];
        while (i >= 0) {
            if (i - length == -1)
                return true;
            if (i - next[i] != length)
                return false;
            i = next[i];
        }
        return true;
    }
};
// @lc code=end

