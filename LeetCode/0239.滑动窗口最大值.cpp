/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
/**
 * 维护一个双端队列来记录最大的一些数字的下标
 * 
**/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;
        if (nums.size() == 0 || k <= 0) {
            return res;
        } else if (k == 1) {
            return nums;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!deque.empty() && deque.front() == i-k) {
                deque.pop_front();
            }
            while (!deque.empty() && nums[i] > nums[deque.back()]) {
                deque.pop_back();
            }
            deque.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[deque.front()]);
            }
        }
        
        return res;
    }
};
// @lc code=end

