/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for (int i = 0; i < s.length(); i++)
            s_map[s[i]]++;
        for (int i = 0; i < t.length(); i++)
            t_map[t[i]]++;
        for (auto it = s_map.begin(); it != s_map.end(); it++)
            if (t_map.count(it->first) == 0 || it->second != t_map[it->first])
                return false;
        return true;
    }
};
// @lc code=end

