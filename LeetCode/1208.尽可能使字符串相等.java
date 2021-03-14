/*
 * @lc app=leetcode.cn id=1208 lang=java
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int[] cost = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            int delta = s.charAt(i) - t.charAt(i);
            cost[i] = delta > 0 ? delta: -delta;
        }
        // 这道题目实际上就是寻找一个cost的子串使得其和不超过cost且长度最大。
        int maxLen = 0, sum = 0, j = 0;
        for (int i = 0; i < cost.length; i++) {
            sum += cost[i];
            while (sum > maxCost) {
                sum -= cost[j];
                j++;
            }
            if (i - j + 1 > maxLen) {
                maxLen = i - j + 1;
            }
        }
        return maxLen;
    }
}
// @lc code=end

