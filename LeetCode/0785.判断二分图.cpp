/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 好题，染色法
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> c(graph.size(), -1);
        for (int i = 0; i < graph.size(); i ++) {
            if (c[i] == -1 && !dfs(graph, c, i, 0)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &s, vector<int> &c, int index, int color) {
        if (c[index] != -1) {
            return c[index] == color;
        }
        c[index] = color;
        for (int i = 0; i < s[index].size(); i++) {
            if (!dfs(s, c, s[index][i], !color)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

