/*
 * @lc app=leetcode.cn id=131 lang=java
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    List<List<String>> res = new ArrayList<>();
    List<String> temp = new ArrayList<>();
    private boolean check(String s) {
        if (s.length() <= 1) {
            return true;
        }
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }

    private void travel(String s) {
        if (s.length() == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 1; i <= s.length(); i ++) {
            String t = s.substring(0, i);
            if (check(t)) {
                temp.add(t);
                travel(s.substring(i));
                temp.remove(temp.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        travel(s);
        return res;
    }
}
// @lc code=end

