/*
 * @lc app=leetcode.cn id=404 lang=java
 *
 * [404] 左叶子之和
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
    int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return 0;
        }
        travel(root.left, 1);
        travel(root.right, 2);
        return sum;
    }

    private void travel(TreeNode root, int kind) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null && kind == 1) {
            sum += root.val;
        }
        travel(root.left, 1);
        travel(root.right, 2);
    }
}
// @lc code=end

