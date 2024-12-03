
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    void get_next(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1])
                j++;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        get_next(next, needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > -1 && haystack[i] != needle[j+1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j+1]) {
                j++;
                if (j > needle.size()) {
                    return i - j;
                }
            }
        }
        return -1;
    }
};
// @lc code=end



    // void get_next(int* next, const string& s) {
    //     int j = 0;
    //     next[0] = 0;
    //     for (int i = 1; i < s.size(); i++) {
    //         while (j > 0 && s[i] != s[j]) {
    //             j = next[j - 1];
    //         }
    //         if (s[i] == s[j]) {
    //             j++;
    //         }
    //         next[i] = j;
    //     } 
    // }
