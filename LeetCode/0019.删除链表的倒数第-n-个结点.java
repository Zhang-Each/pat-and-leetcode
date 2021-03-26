/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len = 0, count = 0;
        ListNode p = head, q = head;
        while (p != null) {
            len ++;
            p = p.next;
        }
        if (len == n) {
            return head.next;
        }
        while (count < len - n - 1) {
            q = q.next;
            count ++;
        }
        q.next = q.next.next;
        return head;
    }
}
// @lc code=end

