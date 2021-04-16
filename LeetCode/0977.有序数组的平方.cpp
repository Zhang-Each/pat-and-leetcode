/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0, right = nums.size() - 1, i = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                res[i --] = nums[right] * nums[right];
                right --;
            } else {
                res[i --] = nums[left] * nums[left];
                left ++;
            }
        }
        return res;
    }
};
// @lc code=end

