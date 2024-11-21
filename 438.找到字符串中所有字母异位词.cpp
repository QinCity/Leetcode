/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> p_map;
        int count;
        if (s.length() < p.length())
            return result;
        for (char& c:p) {
            p_map[c]++;
        }
        // for (int i = 0; i < p.length(); i++) {
        //     p_map[p[i]]++;
        // }
        count  = p_map.size();
        int left = 0;
        int right = 0;
        for (right = 0; right < p.length(); right++) {
            if (p_map.count(s[right])) {
                p_map[s[right]]--;
                if (p_map[s[right]] == 0) {
                    count--;
                }   
            }
        }
        if (count == 0) {
            result.push_back(0);
        }
        for (left = left + 1 ; right < s.length(); right++, left++) {
            if (p_map.count(s[right])) {
                p_map[s[right]]--;
                if (p_map[s[right]] == 0) {
                    count--;
                }   
            } 
            if (p_map.count(s[left - 1])) {
                p_map[s[left - 1]]++;
                if (p_map[s[left - 1]] == 1)
                    count++;
            }
            if (count == 0) {
                result.push_back(left);
            }
        }
        return result;

    }
};
// @lc code=end

