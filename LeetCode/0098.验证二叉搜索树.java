/*
 * @lc app=leetcode.cn id=98 lang=java
 *
 * [98] 验证二叉搜索树
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
    List<Integer> in = new ArrayList<Integer>();
    private void travel(TreeNode root) {
        if (root != null) {
            travel(root.left);
            in.add(root.val);
            travel(root.right);
        }
    }
    public boolean isValidBST(TreeNode root) {
        travel(root);
        for (int i = 0; i < in.size() - 1; i ++) {
            if (in.get(i) >= in.get(i + 1)) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

