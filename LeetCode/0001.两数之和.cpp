/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, vector<int>> number;
        for(int i=0; i<nums.size(); i++) {
            number[nums[i]].push_back(i);
        }
        for(int i=0; i<nums.size(); i++) {
            int want = target - nums[i];
            if(want != nums[i] && number[want].size() > 0) {
                res.push_back(i);
                res.push_back(number[want][0]);
                break;
            } else if(want == nums[i] && number[want].size() >= 2) {
                res.push_back(number[want][0]);
                res.push_back(number[want][1]);
                break;
            }
        }
        return res;
    }
};
// @lc code=end

