/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string temp, res;
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (temp != "") {
                    str.push_back(temp);
                    temp = "";
                }
            }
            i ++;
        }
        if (temp != "") {
            str.push_back(temp);
        }
        for (int j = str.size() - 1; j >= 0; j --) {
            res += str[j];
            if (j != 0) {
                res += " ";
            }
        }
        return res;
    }
};
// @lc code=end

