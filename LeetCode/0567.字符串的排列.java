/*
 * @lc app=leetcode.cn id=567 lang=java
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int[] str1 = new int[26];
        int[] str2 = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            str1[s1.charAt(i) - 'a']++;
            str2[s2.charAt(i) - 'a']++;
        }
        int left = 0, right = s1.length();
        while (right < s2.length()) {
            if (checkSubSequence(str1, str2)) {
                return true;
            }
            str2[s2.charAt(right) - 'a']++;
            right++;
            str2[s2.charAt(left) - 'a']--;
            left++;
        }
        return checkSubSequence(str1, str2);
    }

    private boolean checkSubSequence(int[] a, int[] b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

