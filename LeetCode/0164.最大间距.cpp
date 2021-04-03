/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] += 1;
        }
        auto it = mp.begin();
        int last = it->first, res = 0;
        it ++;
        while (it != mp.end()) {
            if (it->second >= 1) {
                res = max(res, it->first - last);
                last = it->first;
            }
            it ++;
        }
        return res;
    }
};
// @lc code=end

