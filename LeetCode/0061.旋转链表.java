/*
 * @lc app=leetcode.cn id=61 lang=java
 *
 * [61] 旋转链表
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
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null || head.next == null) {
            return head;
        }
        int len = 0, count = 0;
        ListNode p = head, q = head, tail = null, cut = null;
        while (p != null) {
            len ++;
            tail = p;
            p = p.next;
        }
        //System.out.println(tail.val);
        if (k % len == 0) {
            return head;
        } else if (len < k) {
            k %= len;
        }
        p = head;
        while (count < len - k - 1) {
            p = p.next;
            count ++;
        }
        cut = p.next;
        p.next = null;
        tail.next = head;
        return cut;
    }
}
// @lc code=end

