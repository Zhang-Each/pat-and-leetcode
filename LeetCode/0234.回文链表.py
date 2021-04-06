#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head == None or head.next == None:
            return True
        res = ""
        while head != None:
            res += str(head.val)
            head = head.next
        i, j = 0, len(res) - 1
        while i < j:
            if res[i] != res[j]:
                return False
            i += 1
            j -= 1
        return True
# @lc code=end

