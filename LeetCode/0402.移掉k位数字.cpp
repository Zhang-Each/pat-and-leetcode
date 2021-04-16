/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }
        while (k --) {
            int index = 0;
            // 找到第一个比后面的数大的位置删除
            for (int i = 1; i < num.size() && num[i] >= num[i - 1]; i ++) {
                index = i;
            }
            num.erase(index, 1);
        }
        int i = 0;
        while (num[i] == '0') {
            i ++;
        }
        if (i == num.size()) {
            return "0";
        }
        return num.substr(i);
    }
};
// @lc code=end

