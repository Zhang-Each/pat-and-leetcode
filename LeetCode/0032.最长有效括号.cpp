/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    // 看到的一个很nb的思路，试出所有不匹配的括号的位置用1表示，其他的用0表示
    // 问题就转化成了找到最多个数的连续的0
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> nums(s.size(), 0);
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.size() > 0) {
                    st.pop();
                } else {
                    nums[i] = 1;
                }
            }
        }
        while (st.size() > 0) {
            nums[st.top()] = 1;
            st.pop();
        }
        int max = 0, left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                max = right - left > max ? right - left : max;
                left = right + 1;
            }
            right ++;
        }
        max = right - left > max ? right - left : max;
        return max;
    }
};
// @lc code=end

