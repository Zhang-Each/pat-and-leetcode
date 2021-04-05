/*
 * @lc app=leetcode.cn id=275 lang=java
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
    public int hIndex(int[] citations) {
        int res = 0, left = 0, right = citations.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= citations.length - mid) {
                res = Math.max(res, citations.length - mid);
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
}
// @lc code=end

