/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
    string cur_result;
    char num[10] ={' ', ' ', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'}; 
    void getAns(int pos, string &digits) {
        if (pos >= digits.size()) {
            result.push_back(cur_result);
            return;
        }
        int number = digits[pos] - '0';
        int end = (number == 9 || number == 7) ? 4 : 3;
        for (int i = 0; i < end; i++) {
            char tmp = num[number] + i; 
            cur_result.push_back(tmp);
            getAns(pos + 1, digits);
            cur_result.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return result;
        getAns(0, digits);
        return result;    
    }
};
// @lc code=end

