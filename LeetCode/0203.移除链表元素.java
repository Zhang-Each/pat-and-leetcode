/*
 * @lc app=leetcode.cn id=203 lang=java
 *
 * [203] 移除链表元素
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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        ListNode res = new ListNode();
        ListNode p = res;
        res.next = head;
        while (p.next != null) {
            ListNode q = p.next;
            while (q != null && q.val == val) {
                q = q.next;
            }
            p.next = q;
            p = p.next;
            if (p == null) {
                break;
            }
        }
        return res.next;
    }
}
// @lc code=end

