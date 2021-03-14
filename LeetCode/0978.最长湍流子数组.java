/*
 * @lc app=leetcode.cn id=978 lang=java
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
    /** 旧代码，能过90%的测试点
    public int maxTurbulenceSize(int[] arr) {
        if (arr.length <= 2) {
            if (arr.length == 2 && arr[0] == arr[1]) {
                return 1;
            }
            return arr.length;
        }
        int i = 0, j = 0, maxLen = 0;
        while (i < arr.length - 1 && j < arr.length - 1) {
            if (arr[i] < arr[i + 1]) {
                j = i + 1;
                while (j < arr.length - 1) {
                    
                    if ((j - i) % 2 == 0 && (arr[j] < arr[j - 1] && arr[j] < arr[j + 1])) {
                        j++;
                    } else if ((j - i) % 2 == 1 && (arr[j] > arr[j - 1] && arr[j] > arr[j + 1])) {
                        j++;
                    } else {
                        if (j - i + 1 > maxLen) {
                            maxLen = j - i + 1;
                        }
                        break;
                    }
                }
            } else if (arr[i] > arr[i + 1]) {
                j = i + 1;
                while (j < arr.length - 1) {
                    if ((j - i) % 2 == 0 && (arr[j] > arr[j - 1] && arr[j] > arr[j + 1])) {
                        j++;
                    } else if ((j - i) % 2 == 1 && (arr[j] < arr[j - 1] && arr[j] < arr[j + 1])) {
                        j++;
                    } else {
                        if (j - i + 1 > maxLen) {
                            maxLen = j - i + 1;
                        }
                        break;
                    }
                }
            }
            i++;
        }
        return maxLen;
    }
    */
    public int maxTurbulenceSize(int[] arr) {
        int len = 1, maxLen = 1;
        char op = '=';
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1]) {
                len = 1;
                op = '=';
            } else if (arr[i] > arr[i - 1] && op == '<' || arr[i] < arr[i - 1] && op == '>') {
                len++;
            } else {
                len = 2;
            }
            if (len > maxLen) {
                maxLen = len;
            }
            op = arr[i] > arr[i - 1] ? '>': '<';
        }
        return maxLen;
    }

}
// @lc code=end