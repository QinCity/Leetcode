/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        set<char> c;
        int t_start = 0;
        int t_end = 0;
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (c.count(s[i]) == 0) {
                int cur_end;
                c.insert(s[i]);
                for (int j = i; j < s.size(); j++) {
                    if (s[j] == s[i])
                        cur_end = j;
                }
                t_end = max(t_end, cur_end);
            }
            if (t_end == i) {
                result.push_back(t_end - t_start + 1);
                t_start = t_end + 1;
            }
        }
        return result;

        
    }
};
// @lc code=end

