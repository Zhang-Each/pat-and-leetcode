/*
 * @lc app=leetcode.cn id=59 lang=java
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    public int[][] generateMatrix(int n) {
        int left = 0, right = n - 1, top = n - 1, bottom = 0;
        int i = 1;
        int[][] res = new int[n][n];
        while (i <= n * n) {
            for (int j = left; j <= right; j ++) {
                res[bottom][j] = i ++;
            }
            bottom += 1;
            if (i > n * n) {
                break;
            }
            for (int j = bottom; j <= top; j ++) {
                res[j][right] = i ++;
            }
            right -= 1;
            if (i > n * n) {
                break;
            }
            for (int j = right; j >= left; j --) {
                res[top][j] = i ++;
            }
            top -= 1;
            if (i > n * n) {
                break;
            }
            for (int j = top; j >= bottom; j --) {
                res[j][left] = i ++;
            }
            left += 1;
            if (i > n * n) {
                break;
            }
        }
        return res;
    }
}
// @lc code=end

