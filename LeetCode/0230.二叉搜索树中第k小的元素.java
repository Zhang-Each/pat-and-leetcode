/*
 * @lc app=leetcode.cn id=230 lang=java
 *
 * [230] 二叉搜索树中第K小的元素
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
    List<Integer> nums = new ArrayList<Integer>();
    public int kthSmallest(TreeNode root, int k) {
        inOrder(root);
        return nums.get(k - 1);
    }

    private void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.left);
            nums.add(root.val);
            inOrder(root.right);
        }
    }
}
// @lc code=end

