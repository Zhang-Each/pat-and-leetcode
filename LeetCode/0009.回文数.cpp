/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        long n = 0;
        while (x > 0) {
            n = x % 10 + n * 10;
            x /= 10;
        }
        return (int)n == temp;
    }
};
// @lc code=end

