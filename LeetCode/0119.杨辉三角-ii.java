/*
 * @lc app=leetcode.cn id=119 lang=java
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
    public List<Integer> getRow2(int rowIndex) {
        Integer[] res = new Integer[rowIndex + 1];
        Arrays.fill(res, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >0; j--) {
                res[j] += res[j - 1];
            }
        }
        return Arrays.asList(res);
    }

    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<Integer>(rowIndex + 1);
        long temp = 1;
        for (int i = 0; i <= rowIndex; i++) {
            res.add((int)temp);
            temp *= (rowIndex - i);
            temp /= (i + 1);
        }
        return res;
    }
}
// @lc code=end

