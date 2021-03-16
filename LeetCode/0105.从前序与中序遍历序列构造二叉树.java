/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, preorder.length - 1, 0 , inorder.length - 1);
    }

    private TreeNode build(int[] preorder, int[] inorder, int pre1, int pre2, int in1, int in2) {
        if (pre1 > pre2 || in1 > in2) {
            return null;
        }
        TreeNode t = new TreeNode(preorder[pre1], null, null);
        int i = 0, len;
        for (i = in1; i <= in2; i ++) {
            if (inorder[i] == preorder[pre1]) {
                break;
            }
        }
        len = i - in1;
        t.left = build(preorder, inorder, pre1 + 1, pre1 + len, in1, i - 1);
        t.right = build(preorder, inorder, pre1 + len + 1, pre2, i + 1, in2);
        return t;
    }
}
// @lc code=end

