/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        for (int i = 0; i < citations.size(); i ++) {
            int num = citations.size() - i;
            if (num <= citations[i] && num > res) {
                res = num;
            }
        }
        return res;
    }
};
// @lc code=end

