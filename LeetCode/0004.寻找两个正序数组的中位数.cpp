/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0, j = 0, len = nums1.size() + nums2.size();
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size()) {
            nums.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            nums.push_back(nums2[j++]);
        }
        if (len % 2 == 1) {
            return nums[len / 2];
        } else {
            return (nums[len / 2] + nums[len / 2 - 1]) / 2.0;
        }
    }
};
// @lc code=end

