/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_pos = s.length() - 1;
        int t_pos = t.length() - 1;
        while (s_pos >= 0 && t_pos >= 0) {
            if (t[t_pos] == '#') {
                int nums = 1;
                while (nums >= 0) {
                    t_pos--;
                    if (t_pos < 0)
                        break;
                    if (t[t_pos] == '#') {
                        nums++;
                    }
                    else {
                        nums--;
                    }
                }
            }
            if (s[s_pos] == '#') {
                int nums = 1;
                while (nums >= 0) {
                    s_pos--;
                    if (s_pos < 0)
                        break;
                    if (s[s_pos] == '#') {
                        nums++;
                    }
                    else {
                        nums--;
                    }
                }
            }
            if (s_pos < 0 || t_pos < 0) {
                break;
            }
            if (s[s_pos] != t[t_pos])
                return 0;    
            t_pos--;
            s_pos--;
        }
        if (s_pos >=0) {
            if (s[s_pos] == '#') {
                int nums = 1;
                while (nums >= 0) {
                    s_pos--;
                    if (s_pos < 0)
                        break;
                    if (s[s_pos] == '#') {
                        nums++;
                    }
                    else {
                        nums--;
                    }
                }
            }
        }

        if (t_pos >= 0) {
            if (t[t_pos] == '#') {
                int nums = 1;
                while (nums >= 0) {
                    t_pos--;
                    if (t_pos < 0)
                        break;
                    if (t[t_pos] == '#') {
                        nums++;
                    }
                    else {
                        nums--;
                    }
                }
            }
        }


        if (t_pos == s_pos) {
            return 1;
        }
        else
            return 0;
    }
};
// @lc code=end

