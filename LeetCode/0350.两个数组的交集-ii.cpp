/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i ++) {
            mp[nums2[i]] += 1;
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i ++) {
            if (mp[nums1[i]] >= 1) {
                res.push_back(nums1[i]);
                mp[nums1[i]] -= 1;
            }
        }
        return res;
    }
};
// @lc code=end

