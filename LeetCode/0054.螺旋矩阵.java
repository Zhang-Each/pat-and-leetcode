/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int left = 0, right = matrix[0].length - 1, top = matrix.length - 1, bottom = 0;
        int n = matrix.length * matrix[0].length, i = 0;
        List<Integer> res = new ArrayList<>();
        while (res.size() < n) {
            for (int j = left; j <= right; j ++) {
                res.add(matrix[bottom][j]);
            }
            bottom += 1;
            if (res.size() >= n) {
                break;
            }
            for (int j = bottom; j <= top; j ++) {
                res.add(matrix[j][right]);
            }
            right -= 1;
            if (res.size() >= n) {
                break;
            }
            for (int j = right; j >= left; j --) {
                res.add(matrix[top][j]);
            }
            top -= 1;
            if (res.size() >= n) {
                break;
            }
            for (int j = top; j >= bottom; j --) {
                res.add(matrix[j][left]);
            }
            left += 1;
            if (res.size() >= n) {
                break;
            }
        }
        return res;
    }
}
// @lc code=end

