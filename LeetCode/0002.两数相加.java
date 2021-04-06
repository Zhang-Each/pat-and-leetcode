/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
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
// 全新版本，和合并链表类似
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }
        ListNode res = new ListNode();
        ListNode p = res;
        int cp = 0;
        while (l1 != null && l2 != null) {
            ListNode q = new ListNode(l1.val + l2.val + cp);
            cp = q.val / 10;
            q.val = q.val % 10;
            p.next = q;
            p = p.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            ListNode q = new ListNode(l1.val + cp);
            cp = q.val / 10;
            q.val = q.val % 10;
            p.next = q;
            p = p.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            ListNode q = new ListNode(l2.val + cp);
            cp = q.val / 10;
            q.val = q.val % 10;
            p.next = q;
            p = p.next;
            l2 = l2.next;
        }
        while (cp != 0) {
            ListNode q = new ListNode(cp);
            cp = q.val / 10;
            q.val = q.val % 10;
            p.next = q;
            p = p.next;
        }
        return res.next;
    }
}
// @lc code=end

