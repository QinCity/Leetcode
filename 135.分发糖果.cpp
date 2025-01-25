/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
    int getN(int pos, vector<int>& ratings) {
        if (nums[pos] > 0)
            return nums[pos];
        if (pos == 0) {
            if (ratings.size() >= 2) {
                if (ratings[pos] <= ratings[pos + 1])
                    nums[pos] = 1;
                else {
                    nums[pos] = getN(pos + 1, ratings) + 1;
                }
            }
            else
                nums[pos] = 1;
        }
        else if (pos == ratings.size() - 1) {
            if (ratings.size() >= 2) {
                if (ratings[pos] <= ratings[pos - 1])
                    nums[pos] = 1;
                else {
                    nums[pos] = getN(pos - 1, ratings) + 1;
                }
            }
            else 
                nums[pos] = 1;
        } 
        else {
            if (ratings[pos - 1] > ratings[pos]) {
                if (ratings[pos] < ratings[pos + 1])
                    nums[pos] = 1;
                else if (ratings[pos] == ratings[pos + 1]) {
                    nums[pos] = 1;
                }
                else {
                    nums[pos] = getN(pos + 1, ratings) + 1;
                }
            }
            else if (ratings[pos - 1] == ratings[pos]) {
                if (ratings[pos] < ratings[pos + 1])
                    nums[pos] = 1;
                else if (ratings[pos] == ratings[pos + 1]) {
                    nums[pos] = 1;
                }
                else {
                    nums[pos] = getN(pos + 1, ratings) + 1;
                }
            }
            else {
                if (ratings[pos] < ratings[pos + 1])
                    nums[pos] = getN(pos - 1, ratings) + 1;
                else if (ratings[pos] == ratings[pos + 1]) {
                    nums[pos] = getN(pos - 1, ratings) + 1;  
                }
                else {
                    nums[pos] = max(getN(pos - 1, ratings) + 1, getN(pos + 1, ratings) + 1);;
                }
            }
        } 
        return nums[pos];
    }
public:
    int candy(vector<int>& ratings) {
        nums.resize(ratings.size());
        int sum = 0;
        for (int i = 0; i < ratings.size(); i++) {
            if (nums[i] == 0)
                getN(i, ratings);
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end

