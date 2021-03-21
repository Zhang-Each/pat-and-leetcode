/*
 * @lc app=leetcode.cn id=337 lang=java
 *
 * [337] 打家劫舍 III
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
    //好题，使用动态规划可以解决
    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int sum = root.val;
        // 如果偷了当前节点就不能偷左右儿子，要隔一层继续偷
        if (root.left != null) {
            sum += rob(root.left.left) + rob(root.left.right);
        }
        if (root.right != null) {
            sum += rob(root.right.left) + rob(root.right.right);
        }
        return Math.max(sum, rob(root.left) + rob(root.right));
    }
}
// @lc code=end

