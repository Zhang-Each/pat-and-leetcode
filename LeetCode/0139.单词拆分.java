/*
 * @lc app=leetcode.cn id=139 lang=java
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
    // 失败的一个递归方法
    public boolean wordBreak2(String s, List<String> wordDict) {
        if (s.length() == 0) {
            return true;
        }
        int left = 0, right = 1;
        while (right <= s.length()) {
            String t = s.substring(left, right);
            //System.out.println(t);
            if (wordDict.contains(t) && wordBreak(s.substring(right), wordDict)) {
                return true;
            } else {
                right += 1;
            }
        }
        return false;
    }

    // 题解做法，数据记录前i-1个字符能否都被良好拆分
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] can = new boolean[s.length() + 1];
        can[0] = true;
        for (int i = 1; i <= s.length(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (can[j] && wordDict.contains(s.substring(j, i))) {
                    can[i] = true;
                    break;
                }
            }
        }
        return can[s.length()];
    }
}
// @lc code=end

