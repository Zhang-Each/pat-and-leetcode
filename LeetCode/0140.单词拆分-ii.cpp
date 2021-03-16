/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    map<string, int> mp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            mp[wordDict[i]] = 1;
        }
        travel(s);
        vector<string> result;
        for (int i = 0; i < res.size(); i ++) {
            string temp;
            for (int j = 0; j < res[i].size(); j ++) {
                if (j != 0) {
                    temp += " ";
                }
                temp += res[i][j];
            }
            result.push_back(temp);
        }
        return result;
    }

    void travel(string s) {
        if (s == "") {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i ++) {
            string t = s.substr(0, i);
            if (mp[t] == 1) {
                path.push_back(t);
                travel(s.substr(i));
                path.pop_back();
            }
        }
    }
};
// @lc code=end

