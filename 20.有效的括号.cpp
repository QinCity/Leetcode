/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                a.push(s[i]);
            else {
                if (a.empty())
                    return 0;
                if (s[i] == ')' && a.top() == '(')
                    a.pop();
                else if (s[i] == ']' && a.top() == '[')
                    a.pop();
                else if (s[i] == '}' && a.top() == '{')
                    a.pop();
                else
                    return false;
            }
        }
        if (a.empty())
            return 1;
        else
            return 0;
        
    }
};
// @lc code=end

