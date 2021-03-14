/*
 * @lc app=leetcode.cn id=75 lang=java
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
        int red = 0, white = 0;
        for (int i = 0; i < nums.length; i ++) {
            switch (nums[i]) {
                case 0:
                    red ++;
                    break;
                case 1:
                    white ++;
                    break;
                default:
                    break;
            }
        }
        for (int i = 0; i < red; i ++) {
            nums[i] = 0;
        }
        for (int i = red; i < red + white; i ++) {
            nums[i] = 1;
        }
        for (int i = red + white; i < nums.length; i ++) {
            nums[i] = 2;
        }
    }
    // 另一种解法
    public void sortColors2(int[] nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                nums[num2++] = 2;
                nums[num1++] = 1;
                nums[num0++] = 0;
            } else if(nums[i] == 1) {
                nums[num2++] = 2;
                nums[num1++] = 1;
            } else {
                nums[num2++] = 2;
            }
        }
    }
}
// @lc code=end

