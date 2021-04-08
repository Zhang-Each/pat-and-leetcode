/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        stack<int> s;
        s.push(0);
        int res = 0;
        // 为什么是单调递减栈，因为如果i在栈里，那么比a[i]大的且排在a[i]后面的数的最大宽坡度不可能超过i的
        for (int i = 1; i < a.size(); i ++) {
            if (a[i] < a[s.top()]) {
                s.push(i);
            }
        }
        for (int i = a.size() - 1; i >= 0; i --) {
            while (!s.empty() && a[i] >= a[s.top()]) {
                res = max(res, i - s.top());
                s.pop();
            }
        }
        return res;
    }
};
// @lc code=end

