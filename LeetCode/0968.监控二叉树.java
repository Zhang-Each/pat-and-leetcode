/*
 * @lc app=leetcode.cn id=968 lang=java
 *
 * [968] 监控二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int res = 0;
    public int minCameraCover(TreeNode root) {
        if (root == null) {
            return res;
        }
        if (dfs(root) == 2) {
            res += 1;
        }
        return res;
    }

    private int dfs(TreeNode root) {
        if (root == null) {
            return 1;
        }
        int left = dfs(root.left), right = dfs(root.right);
        if (left == 2 || right == 2) {
            res ++;
            return 0;
        } else if (left == 0 || right == 0) {
            return 1;
        }
        return 2;
    }
}
// @lc code=end

