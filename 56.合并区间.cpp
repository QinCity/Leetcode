/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        vector<int> result;

        sort(intervals.begin(), intervals.end());    
        result.push_back(intervals[0][0]);
        result.push_back(intervals[0][1]); 
     
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result[1]) {
                result[0] = min(result[0], intervals[i][0]);
                result[1] = max(result[1], intervals[i][1]);
            }
            else {
                results.push_back(result);
                result[0] = intervals[i][0];
                result[1] = intervals[i][1];
                
            }
        }
        results.push_back(result);
        return results;
    }
};
// @lc code=end

