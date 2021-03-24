/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern2(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int min = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > min) {
                for (int j = i + 1; j < nums.size(); j ++) {
                    if (nums[j] < nums[i] && nums[j] > min) {
                        return true;
                    }
                }
            } else {
                min = nums[i];
            }
        }
        return false;
    }

    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> s;
        int min = -1000000000;
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (nums[i] < min) {
                return true;
            }
            while (s.size() > 0 && s.back() < nums[i]) {
                min = s.back();
                s.pop_back();
            }
            s.push_back(nums[i]);
        }
        return false;
    }
};
// @lc code=end

