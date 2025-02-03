/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> &b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        int start, end;
        start = intervals[0][0];
        end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                start = max(start, intervals[i][0]);
                end = min(end, intervals[i][1]);
            }
            else {
                start = intervals[i][0];
                end = intervals[i][1];
                result++;
            }
        }
        result++;
        return intervals.size() - result;
    }
};
// @lc code=end

