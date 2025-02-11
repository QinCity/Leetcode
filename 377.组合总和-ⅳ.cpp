/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // int N = nums.size();

        // vector<vector<int>> dp(N, vector<int>(target + 1));
        // for (int i = 0; i <= target; i++) {
        //     if (i % nums[0] == 0)
        //        dp[0][i] = 1;
        // }
        // for (int i = 0; i < N; i++) {
        //     dp[i][0] = 1;
        // }
        // for (int j = 1; j <= target; j++){
        //     for (int i = 1; i < N; i++)  {

        //         dp[i][j] = dp[i - 1][j];
        //         if (j - nums[i] >= 0) {
        //             dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]];
        //         }
        //     }
        // }
        // return dp[N - 1][target];
        vector<vector<unsigned>> dp(nums.size(),vector<unsigned>(target+1,0));
        for(int i = 0;i<nums.size();i++) { 
            dp[i][0] = 1; 
        } 
        for(int j = 1;j<=target;j++) { 
            for(int i = 0;i<nums.size();i++){ 
                if(i!=0){ 
                    dp[i][j] += dp[i-1][j]; 
                }  
                if(j>=nums[i]){ 
                    dp[i][j] += dp[nums.size()-1][j - nums[i]]; 
                } 
            cout<<dp[i][j]<<' '; 
            } 
        cout<<endl; 
        }  
        return dp[nums.size()-1][target];
    }
};
// @lc code=end

