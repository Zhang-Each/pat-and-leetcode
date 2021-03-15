/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    List<String> res = new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
        travel(n, "", 0, 0);
        return res;
    }

    private void travel(int n, String x, int num1, int num2) {
        if (num1 > n || num2 > n) {
            return;
        }
        if (num1 == n && num2 == n) {
            res.add(x);
            return;
        }
        if (num1 >= num2) {
            String y = new String(x);
            travel(n, x + "(", num1 + 1, num2);
            travel(n, y + ")", num1, num2 + 1);
        } else return;
    } 
}
// @lc code=end

