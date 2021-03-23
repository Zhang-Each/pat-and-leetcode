/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int count = 0;
            while(n != 0){
                if(n % 2 == 1){
                    count ++;
                }
                n = n / 2;
            }
            return count;
        }
    };
// @lc code=end

