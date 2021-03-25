/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */
#include <string>
using namespace std;
// @lc code=start
// 这个方法最后几个测试点会超时，但是总的来说可以使用
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return check(s1, s2, s3, 0, 0, 0);
    }

    bool check(string s1, string s2, string s3, int i, int j, int k) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }
        if (s1[i] == s3[k] && check(s1, s2, s3, i + 1, j, k + 1)) {
            return true;
        }
        if (s2[j] == s3[k] && check(s1, s2, s3, i, j + 1, k + 1)) {
            return true;
        }
        return false;
    }
};
// @lc code=end

