/*
 * @lc app=leetcode.cn id=125 lang=java
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
    private boolean legal(char x) {
        return x >= '0' && x <= '9' || x >= 'a' && x <= 'z';
    }
    public boolean isPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        s = s.toLowerCase();
        StringBuilder t = new StringBuilder();
        for (int i = 0; i < s.length(); i ++) {
            if (legal(s.charAt(i))) {
                t.append(s.charAt(i));
            }
        }
        int left = 0, right = t.length() - 1;
        while (left < right) {
            if (t.charAt(left) != t.charAt(right)) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
}

// @lc code=end

