/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <map>
using namespace std;

// @lc code=start
// 这题最后一个测试点过不了，不知道为什么
class Solution {
public:
    map<char, int> mt;
    bool check(map<char, int> m) {
        for (auto it = mt.begin(); it != mt.end(); it ++) {
            if (m[it->first] < it->second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        } else if (t == s) {
            return s;
        }
        for (int i = 0; i < t.size(); i ++) {
            mt[t[i]] += 1;
        }
        int left = 0, right = 0, start = 0, len = s.size() + 1;
        map<char, int> mp;
        while (right < s.size()) {
            mp[s[right++]] += 1;
            while (check(mp)) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                mp[s[left++]] -= 1;
            }
        }
        if (len == s.size() + 1) {
            return "";
        }
        return s.substr(start, len);
    }
};
// @lc code=end

