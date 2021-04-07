/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <stack> 
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 好题，没想到easy也这么难，这种数据结构叫做单调栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> next;
        stack<int> s; 
        for (int i = 0; i < nums2.size(); i ++) {
            while (!s.empty() && s.top() < nums2[i]) {
                int x = s.top();
                s.pop();
                next[x] = nums2[i];
            }
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i ++) {
            if (next[nums1[i]] != 0) {
                res.push_back(next[nums1[i]]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end

