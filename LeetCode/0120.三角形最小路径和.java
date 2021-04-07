/*
 * @lc app=leetcode.cn id=120 lang=java
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> s) {
        if (s.size() == 1) {
            return s.get(0).get(0);
        }
        int n = s.size();
        int[][] a = new int[n + 1][n + 1];
        a[0][0] = s.get(0).get(0);
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (j == 0) {
                    a[i][j] = a[i - 1][0] + s.get(i).get(0);
                } else if (j == i) {
                    a[i][j] = a[i - 1][i - 1] + s.get(i).get(i);
                } else {
                    a[i][j] = Math.min(a[i - 1][j], a[i - 1][j - 1]) + s.get(i).get(j);
                }
            }
        }
        int res = a[n - 1][0];
        for (int i = 0; i < n; i ++) {
            if (a[n - 1][i] < res) {
                res = a[n - 1][i];
            }
        }
        return res;
    }
}
// @lc code=end

