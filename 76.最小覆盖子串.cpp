/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cnt;
        string result;
        int left = 0, right, none_zero = 0, min_bound = 0, max_bound = s.length();
        bool exist = 0;
        for (int i = 0; i < t.length(); i++) {
            cnt[t[i]]++;
        }
        none_zero = cnt.size();
        for (right = 0; right < s.length(); right++) {
            if (cnt.find(s[right]) != cnt.end()) {
                cnt[s[right]]--;
                if (cnt[s[right]] == 0) {
                    none_zero--;
                }
            }
            while (none_zero == 0) {
                exist = 1;
                if (right - left + 1 < max_bound - min_bound + 1){
                    max_bound = right;
                    min_bound = left;
                }
                if (cnt.find(s[left]) != cnt.end()) {
                    cnt[s[left]]++;
                    if (cnt[s[left]] == 1) {
                        none_zero++;
                    }
                }
                left++;
            }
        }
        if (exist == 1)
            result = s.substr(min_bound, max_bound - min_bound + 1);
        return result;
    }
};
// @lc code=end

