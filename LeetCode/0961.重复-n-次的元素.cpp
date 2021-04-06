/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> mp;
        for (int i = 0; i < A.size(); i ++) {
            mp[A[i]] += 1;
            if (mp[A[i]] >= 2) {
                return A[i];
            }
        }
        return 0;
    }
};
// @lc code=end

