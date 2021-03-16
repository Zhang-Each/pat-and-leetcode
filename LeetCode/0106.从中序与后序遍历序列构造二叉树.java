/*
 * @lc app=leetcode.cn id=106 lang=java
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return build(postorder, inorder, 0, postorder.length - 1, 0, inorder.length - 1);
    }

    private TreeNode build(int[] post, int[] in, int post1, int post2, int in1, int in2) {
        if (post1 > post2 || in1 > in2) {
            return null;
        }
        TreeNode t = new TreeNode(post[post2]);
        int i, len;
        for (i = in1; i <= in2; i ++) {
            if (in[i] == post[post2]) {
                break;
            }
        }
        len = i - in1;
        t.left = build(post, in, post1, post1 + len - 1, in1, i - 1);
        t.right = build(post, in, post1 + len, post2 - 1, i + 1, in2);
        return t;
    }
}
// @lc code=end

