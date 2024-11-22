/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int exist1[1001] = {0};
        int exist2[1001] = {0};
        vector<int> result;
        for (int& num1: nums1) {
            exist1[num1] = 1;
        }
        for (int& num2: nums2) {
            exist2[num2] = 1;
        }
        for(int i = 0; i <= 1000; i++) {
            if (exist1[i] == 1 && exist2[i] == 1)
                result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

