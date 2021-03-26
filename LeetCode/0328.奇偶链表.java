/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode x = head, y = head.next, head2 = head.next;
        while (x.next != null && y.next != null) {
            x.next = y.next;
            x = x.next;
            y.next = x.next;
            y = y.next;
        }
        x.next = head2;
        return head;
    }
}
// @lc code=end

