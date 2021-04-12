#
# @lc app=leetcode.cn id=1022 lang=python3
#
# [1022] 从根到叶的二进制数之和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = 0
    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.travel(root, "")
        return self.res
    def travel(self, root: TreeNode, num: str):
        if root == None:
            return
        num += str(root.val)
        if root.left == None and root.right == None:
            self.res += int(num, 2)
        self.travel(root.left, num)
        self.travel(root.right, num)

        
# @lc code=end

