/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < s.size(); i ++) {
            q.push(s[i]);
        }
        while (q.size() >= 2) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if (x - y > 0) {
                q.push(x - y);
            }
        }
        return q.size() == 1 ? q.top() : 0;
    }
};
// @lc code=end

