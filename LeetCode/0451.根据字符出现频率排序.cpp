/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <string>
#include <queue>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> fq;
        for (int i = 0; i < s.size(); i ++) {
            fq[s[i]] += 1;
        }
        priority_queue<pair<int, char>> q;
        for (auto i = fq.begin(); i != fq.end(); i ++) {
            if (i->second > 0) {
                pair<int, char> temp(i->second, i->first);
                q.push(temp);
            }
        }
        string res;
        while (q.size() > 0) {
            pair<int, char> t = q.top();
            q.pop();
            for (int i = 0; i < t.first; i ++) {
                res += t.second;
            }
        }
        return res;
    }
};
// @lc code=end

