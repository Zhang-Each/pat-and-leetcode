/*
 * @lc app=leetcode.cn id=36 lang=java
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] b) {
        for (int i = 0; i < 9; i ++) {
            int[] check = new int[10];
            for (int j = 0; j < 9; j ++) {
                if (b[i][j] != '.') {
                    check[b[i][j] - '0'] ++;
                    if (check[b[i][j] - '0'] >= 2) {
                        return false;
                    }
                }
            }
            int[] check2 = new int[10];
            for (int j = 0; j < 9; j ++) {
                if (b[j][i] != '.') {
                    check2[b[j][i] - '0'] ++;
                    if (check2[b[j][i] - '0'] >= 2) {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int[] check = new int[10];
                for (int m = i; m < i + 3; m ++) {
                    for (int n = j; n < j + 3; n ++) {
                        if (b[m][n] != '.') {
                            check[b[m][n] - '0'] ++;
                            if (check[b[m][n] - '0'] >= 2) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
}

// @lc code=end

