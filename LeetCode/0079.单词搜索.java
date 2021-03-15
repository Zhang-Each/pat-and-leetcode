/*
 * @lc app=leetcode.cn id=79 lang=java
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 || board[0].length == 0) {
            return false;
        }
        for (int i = 0; i < board.length; i ++) {
            for (int j = 0; j < board[0].length; j ++) {
                if (find(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean find(int i, int j, int index, String w, char[][] b) {
        if (index >= w.length()) {
            return true;
        }
        if (i < 0 || i >= b.length || j < 0 || j >= b[0].length || b[i][j] != w.charAt(index)) {
            return false;
        }
        b[i][j] += 256;
        boolean res = find(i + 1, j, index + 1, w, b) || find(i - 1, j, index + 1, w, b) || find(i, j - 1, index + 1, w, b) || find(i, j + 1, index + 1, w, b);
        b[i][j] -= 256;
        return res;
    }
}
// @lc code=end

