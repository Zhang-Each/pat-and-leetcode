/*
 * @lc app=leetcode.cn id=132 lang=java
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
    public int minCut(String s) {
        if (s.length() <= 1) {
            return 0;
        }
        int size = s.length();
        boolean[][] check = new boolean[size][size];
        for (int i = size - 1; i >= 0; i --) {
            check[i][i] = true;
            for (int j = i + 1; j < size; j ++) {
                if (j == i + 1) {
                    check[i][j] = s.charAt(i) == s.charAt(j);
                } else {
                    check[i][j] = s.charAt(i) == s.charAt(j) && check[i + 1][j - 1];
                }
            }
        }
        // res[i]表示0-i之间的s子串需要的最少分割次数
        int[] res = new int[size];
        for (int i = 0; i < size; i ++) {
            res[i] = i;
            // 剪枝操作，如果0-i就是回文，最少分割次数就是0
            if (check[0][i]) {
                res[i] = 0;
                continue;
            }
            // 转移方程：如果j + 1 - i + 1是回文，就可以考虑res[j]+1次分割
            for (int j = 0; j < i; j ++) {
                if (check[j + 1][i]) {
                    res[i] = Math.min(res[i], res[j] + 1);
                }
            }
        }
        return res[size - 1];
    }
}
// @lc code=end

