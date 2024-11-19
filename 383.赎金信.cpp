/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ran_map;
        int cal;
        for (int i = 0; i < ransomNote.size(); i++) {
            ran_map[ransomNote[i]]++;
        } 
        cal = ran_map.size();
        for (int i = 0; i < magazine.size(); i++) {
            if (ran_map.count(magazine[i]) == 1) {
                ran_map[magazine[i]]--;
                if (ran_map[magazine[i]] == 0)
                cal--;
            }
        }
        if (cal == 0)
            return true;
        else 
            return false;
    }
};
// @lc code=end

