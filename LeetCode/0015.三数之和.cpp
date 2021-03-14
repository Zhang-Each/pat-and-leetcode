/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>,int> m;
        vector<vector<int>> result;
        if(nums.size() <= 2) return result;
        sort(nums.begin(), nums.end());
        if(nums[0] == 0&&nums[nums.size()-1] == 0){
            return {{0,0,0}};
        }
        int i,j,k;
        for(i=0;i<nums.size()-2;i++){
            j=i+1;
            k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    m[{nums[i],nums[j],nums[k]}]+=1;
                    j++;
                }
                else if(nums[j]+nums[k]<-nums[i])
                    j++;
                else if(nums[j]+nums[k]>-nums[i])
                    k--;
            }
        }
        map<vector<int>,int>::iterator x;
        for(x=m.begin();x!=m.end();x++){
            result.push_back(x->first);
        }
        return result;
    }
};
// @lc code=end

