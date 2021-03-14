/*
 * @lc app=leetcode.cn id=765 lang=java
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
    public int minSwapsCouples(int[] row) {
        int res = 0;
        for (int i = 0; i < row.length; i += 2) {
            int target;
            if (row[i] % 2 == 0) {
                target = row[i] + 1;
            } else {
                target = row[i] - 1;
            }
            if (row[i + 1] != target) {
                /**
                 * 这里把原来的j=0改成j=i+2时间立马击败100%
                 */
                for (int j = i + 2; j < row.length; j++) {
                    if (row[j] == target) {
                        target = row[i + 1];
                        row[i + 1] = row[j];
                        row[j] = target;
                        break;
                    }
                }
                res++;
            }
        }
        return res;
    }
}
// @lc code=end

