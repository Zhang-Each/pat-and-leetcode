/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int res = 0;
    void find_a_little(string s) {
        if (s == "0" || s .size() == 0) {
            return;
        } else if (s.size() == 1) {
            res += 1;
            return;
        }
        int num = s[0] - '0';
        for (int i = 0; i < num; i ++) {
            res += pow(10, s.size() - 2) * (s.size() - 1);
            if (i == 1) {
                res += pow(10, s.size() - 1);
            }
        }
        string t = s.substr(1, s.size() - 1);
        if (num == 1) {
            res += atoi(t.c_str()) + 1;
        }
        find_a_little(t);
    }

    int countDigitOne(int n) {
        if (n <= 1) {
            return n;
        }
        find_a_little(to_string(n));
        return res;
    }
};
// @lc code=end

