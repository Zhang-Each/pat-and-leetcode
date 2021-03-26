/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        vector<int> nums;
        string res;
        if (num < 0) {
            num *= -1;
            res += '-';
        }
        while (num > 0) {
            nums.push_back(num % 7);
            num /= 7;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            res += nums[i] + '0';
        }
        return res;
    }
};
// @lc code=end

