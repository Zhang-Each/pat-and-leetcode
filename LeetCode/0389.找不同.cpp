/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */
#include <string>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mp;
        int res = -1;
        for (int i = 0; i < s.size(); i ++) {
            mp[s[i]] ++;
        }
        for (int i = 0; i < t.size(); i ++) {
            mp[t[i]] --;
            if (mp[t[i]] < 0) {
                res = i;
            }
        }
        return t[res];
    }
};
// @lc code=end

