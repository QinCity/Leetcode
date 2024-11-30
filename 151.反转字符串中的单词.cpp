/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    void reverse_word(string& s, int left, int right) {
        for (; left < right; left++, right--) {
            swap(s[right], s[left]);
        }
    }

    string reverseWords(string s) {
        int start = 0;
        int end;
        reverse_word(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                s[start++] = s[i];
            }
            else {
                if (i > 0 && s[i - 1] != ' ') {
                    s[start++] = ' ';
                }
                
            }
        }
        if (s[start - 1] == ' ') // 此处忘记了start结束之后是start+1
            s.resize(start - 1);
        else 
            s.resize(start);
            
        start = 0;
        for (int i = 1; i < s.size(); i++ ){
            if (s[i] == ' ' && s[i - 1] != ' ') {
                reverse_word(s, start, i - 1);
                end = i - 1;
            }
            else if (s[i - 1] == ' ' && s[i] != ' ')
                start = i;
        }
        reverse_word(s, start, s.size() - 1);
        return s;
    }
};
// @lc code=end

