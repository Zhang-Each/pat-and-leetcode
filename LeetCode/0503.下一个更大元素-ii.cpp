/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> s; 
        for (int i = 0; i < 2 * nums.size(); i ++) {
            int j = i % nums.size();
            while (!s.empty() && nums[s.top()] < nums[j]) {
                int x = s.top();
                s.pop();
                res[x] = nums[j];
            }
            s.push(j);
        }
        return res;
    }
};
// @lc code=end

