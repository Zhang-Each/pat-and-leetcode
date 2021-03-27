/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    // 好题，栈的使用方式
    string decodeString(string s) {
        int num = 0;
        string res;
        stack<int> nums;
        stack<string> st;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                st.push(res);
                res = "";
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            } else {
                for (int j = 0; j < nums.top(); j ++) {
                    st.top() += res;
                }
                res = st.top();
                st.pop();
                nums.pop();
            }
        }
        return res;
    }
};
// @lc code=end

