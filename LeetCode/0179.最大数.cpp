/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i ++) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), cmp);
        string res = "";
        for (int i = 0; i < strs.size(); i ++) {
            res += strs[i];
        }
        int start = 0;
        while (res[start] == '0') {
            start ++;
        }
        if (start == res.size()) {
            return "0";
        }
        return res.substr(start);
    }
};
// @lc code=end

