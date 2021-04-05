/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U') {
                v.push_back(s[i]);
            }
        }
        reverse(v.begin(), v.end());
        int j = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U') {
                s[i] = v[j ++];
            }
        }
        return s;
    }
};
// @lc code=end

