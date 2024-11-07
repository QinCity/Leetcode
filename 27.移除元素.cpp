/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int front = 0, back = 0;
        int num = nums.size();
        while (back < num) {
            if (nums[back] != val) {
                nums[front] = nums[back];
                front++;
            }
            back++;   
        }
        return front;
    }
};
// @lc code=end



// -----法一:数组-----------
    // void getNeibor(int& right, vector<int>& nums, int val) {
    //     for (; right >= 0; right--) {
    //         if (nums[right] != val)
    //             break;
    //     }
    // }

    //         int left = 0, right = nums.size() - 1;
    //     if (right < 0)
    //         return 0;
    //     getNeibor(right, nums, val);
    //     if (right < 0)
    //         return 0;
    //     while (left < right) {
    //         if (nums[left] == val) {
    //             nums[left] = nums[right];
    //             nums[right] = val;
    //             getNeibor(right, nums, val);
    //         }
    //         left++;
    //     }
    //     return right + 1;


//-----------法二:删除元素-------------
        // int left = 0;
        // int num = nums.size() - 1;
        // while (left <= num) {
        //     if (nums[left] == val) {
        //         swap(nums[left], nums[num]);
        //         while (num >= 0 && nums[num] == val){
        //             num--;
        //             nums.pop_back(); 
        //         } 
        //     }
        //     else
        //         left++;
        // }
        // return nums.size(); 