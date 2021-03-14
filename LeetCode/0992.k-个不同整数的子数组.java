/*
 * @lc app=leetcode.cn id=992 lang=java
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {

    /** 第一次失败的代码
     * public int subarraysWithKDistinct(int[] a, int k) {
        int res = 0;
        if (k == 1) {
            res += a.length;
        }
        int i = 0, j = 0;
        for (int i = 0; i <= a.length - k; i++) {
            int len = 1;
            HashSet<Integer> s = new HashSet<Integer>();
            s.add(a[i]);
            for (int j = i + 1; j < a.length; j++) {
                int currentSize = s.size();
                s.add(a[j]);
                if (currentSize != s.size()) {
                    len++;
                }
                if (len == k) {
                    res++;
                } else if (len > k) {
                    break;
                }
            }
        }
        return res;
    }
     */

    private int subarraysWithKDistinct(int[] nums, int k) {
        int len = 0, res = 0, left = 0, right = 0;
        
        for (int i = 0; i <= nums.length - k; i++) {
            Map<Integer, Integer> map = new HashMap<>();
            for (int j = i; j < nums.length; j++) {
                map.put(nums[j], map.getOrDefault(nums[right], 0) + 1);
                if (map.size() == k) {
                    res++;
                } else if (map.size() > k) {
                    break;
                }
            }
        }
        return res;
    }
}
// @lc code=end

