/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    struct node {
        int index;
        int len;
        node(int i, int x, int y) {
            index = i;
            len = x * x + y * y;
        }
        bool operator >(node y) const {
            return len > y.len;
        }
    };
    static bool cmp(node &x, node &y) {
        return x.len < y.len;
    }
    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
        vector<node> res;
        for (int i = 0; i < points.size(); i ++) {
            node t(i, points[i][0], points[i][1]);
            res.push_back(t);
        }
        sort(res.begin(), res.end(), cmp);
        vector<vector<int>> result;
        for (int i = 0; i < k; i ++) {
            result.push_back(points[res[i].index]);
        }
        return result;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<node, vector<node>, greater<node>> q;
        for (int i = 0; i < points.size(); i ++) {
            node t(i, points[i][0], points[i][1]);
            q.push(t);
        }
        vector<vector<int>> result;
        for (int i = 0; i < k; i ++) {
            result.push_back(points[q.top().index]);
            q.pop();
        }
        return result;
    }
};
// @lc code=end

