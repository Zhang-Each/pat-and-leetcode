/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

// @lc code=start
// 这题没过，先不管了
#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int count = 0, maxl = 0;
        for (int i = 0; i < strs.size(); i ++) {
            if (strs[i].size() > maxl) {
                maxl = strs[i].size();
                count = 1;
            } else if (strs[i].size() == maxl) {
                count += 1;
            }
        }
        if (count == 1) {
            return maxl;
        }
        set<string> s;
        for (int i = 0; i < strs.size(); i ++) {
            if (strs[i].size() == maxl) {
                s.insert(strs[i]);
            }
        }
        if (s.size() == count) {
            return maxl;
        } else {
            return -1;
        }
    }
};
// @lc code=end

