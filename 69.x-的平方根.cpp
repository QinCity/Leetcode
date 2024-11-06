/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {

    }
};
// @lc code=end



//------------------- 方法1：暴力 ----------------------
        // for (int i = 0; i < 46341; i++) {
        //     if (i * i >= x) {
        //         return i - 1;
        //     }
        // }
        // return 46340;

//------------------- 方法2：二分 ----------------------
        // long left = 0, right = x, mid;
        // while (left <= right) {
        //     mid = (right + left) / 2;
        //     long tmp = mid * mid;
        //     if (tmp == x)
        //         return mid;
        //     else if (tmp > x) {
        //         right = mid - 1;
        //     }
        //     else {
        //         left = mid + 1;
        //     }
        // }
        // return right;

//-------------------- 方法3:牛顿法 --------------------
