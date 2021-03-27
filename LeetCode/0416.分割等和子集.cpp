/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 自己写的回溯没有通过
    bool canPartition2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        return find(sum, 0, nums);
    }

    bool find(int target, int index, vector<int>& nums) {
        if (target == 0) {
            return true;
        }
        for (int i = index; i < nums.size(); i ++) {
            if (target - nums[i] >= 0 && find(target - nums[i], i + 1, nums)) {
                return true;
            } else if (target - nums[i] < 0) {
                return false;
            }
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int e : nums) sum += e;
        if(sum & 1) return false;
        vector<bool> d((sum>>=1)+1, false);//sum/=2
        for(int i = 0 ; i < nums.size() ; i++){
            for(int s = sum ; s >= nums[i] ; s--){//从后往前，因为前面的元素我们已经求过了(i>0时确实已经求过了，i==0时我们求一遍即可，下面的代码也确实给出了i==0的情况)，可以直接用
                if(!i) d[s] = (nums[i]==s);//i==0要单独求{ nums[0]一个元素和为s }
                else d[s] = d[s] || d[s-nums[i]];
            }
        }
        return d[sum];
    }
};
// @lc code=end

