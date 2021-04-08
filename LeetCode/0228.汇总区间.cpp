/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (right < nums.size() - 1 && nums[right] == nums[right + 1] - 1) {
                right ++;
            }
            if (right == left) {
                res.push_back(to_string(nums[left]));
            } else {
                string temp = to_string(nums[left]) + "->" + to_string(nums[right]);
                res.push_back(temp);
            }
            right += 1;
            left = right;
        }
        return res;
    }
};
// @lc code=end

