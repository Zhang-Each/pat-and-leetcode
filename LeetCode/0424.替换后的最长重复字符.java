/*
 * @lc app=leetcode.cn id=424 lang=java
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
    public int characterReplacement(String s, int k) {
        int res = 0;
        int[] word = new int[26];
        for (int i = 0, j  = 0; j < s.length(); j++) {
            word[s.charAt(j) - 'A']++;
            if (!canReplaycement(word, k)) {
                word[s.charAt(i) - 'A']--;
                i++;
            }
            if (j - i + 1 > res) {
                res = j - i + 1;
            }
        }
        return res;
    }

    private boolean canReplaycement(int[] x, int k) {
        int max = 0, sum = 0;
        for (int i = 0; i < 26; i++) {
            if (x[i] > max) {
                max = x[i];
            }
            sum += x[i];
        }
        return sum - max <= k;
    }
}
// @lc code=end

