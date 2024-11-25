/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum12, sum34;
        int num = 0;
        for (int& i:nums1) {
            for (int& j:nums2) {
                sum12[i+j]++;
            }
        }
        
        for (int& i:nums3) {
            for (int& j:nums4) {
                sum34[i+j]++;
            }
        }

        for (auto it = sum12.begin(); it != sum12.end(); it++) {
            if (sum34.count(-it->first) == 1) {
                num += it->second * sum34[-it->first];
            }
        }    
        return num;    

    }
};
// @lc code=end

