/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    vector<string> cur_divide;
public:
    bool isRound(string &s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) 
                return false;
        }
        return true;
    }

    void traverse(string &s, int begin ,int end) {
        if (end >= s.size()) {
            result.push_back(cur_divide);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            if (isRound(s, begin, end)) {
                string cur_str(s.begin() + begin, s.begin() + end + 1);
                cur_divide.push_back(cur_str);
                traverse(s, end + 1, end + 1);
                cur_divide.pop_back();
            }
            end++;
        }
    }

    vector<vector<string>> partition(string s) {
        traverse(s, 0, 0);
        return result;
    }
};
// @lc code=end

