/*
 * @lc app=leetcode.cn id=48 lang=java
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length, t;
        for (int i = 0; i < n / 2; i ++) {
            for (int j = 0; j < n; j ++) {
                t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = t;
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}
// @lc code=end

