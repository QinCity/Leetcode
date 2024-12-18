/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> result;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (!result.empty() && result.top() == s[i]) {
                result.pop();
            }
            else {
                result.push(s[i]);
            }
        }
        while (!result.empty()) {
            res += result.top();
            result.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
// @lc code=end

