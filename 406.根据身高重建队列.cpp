/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] > b[0])
            return true;
        else if (a[0] == b[0]) {
            if (a[1] < b[1])
                return true;
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); i++) {
           result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};
// @lc code=end

