/*
 * @lc app=leetcode.cn id=129 lang=java
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        return getPathSum(root, 0);
    }
    private int getPathSum(TreeNode root, int sum) {
        if (root == null) {
            return 0;
        } else {
            if (root.left == null && root.right == null) {
                return 10 * sum + root.val;
            }
            return getPathSum(root.left, sum * 10 + root.val) + getPathSum(root.right, sum * 10 + root.val);
        }
    }
}
// @lc code=end

