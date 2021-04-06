/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }
        ListNode res = new ListNode();
        ListNode p = res;
        while (l1 != null && l2 != null) {
            ListNode q = new ListNode();
            if (l1.val < l2.val) {
                q.val = l1.val;
                l1 = l1.next;
            } else {
                q.val = l2.val;
                l2 = l2.next;
            }
            p.next = q;
            p = p.next;
        }
        while (l1 != null) {
            ListNode q = new ListNode(l1.val);
            l1 = l1.next;
            p.next = q;
            p = p.next;
        }
        while (l2 != null) {
            ListNode q = new ListNode(l2.val);
            l2 = l2.next;
            p.next = q;
            p = p .next;
        }
        return res.next;
    }
}
// @lc code=end

