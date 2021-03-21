/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> res;
            map<int, int> fre;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            for (int i = 0; i < nums.size(); i ++) {
                fre[nums[i]] += 1;
            }
            for (auto p = fre.begin(); p != fre.end(); p ++) {
                if (p->second != 0) {
                    q.emplace(p->second, p->first);
                    if (q.size() > k) {
                        q.pop();
                    }
                }
            }
            while (!q.empty()) {
                res.push_back(q.top().second);
                q.pop();
            }
            return res;
        }
    };
// @lc code=end

