/*
 * @lc app=leetcode.cn id=25 lang=java
 *
 * [25] K 个一组翻转链表
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
    // 事实上就是反转链表的变式，用递归可以降低时间复杂度
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k == 1 || head == null || head.next == null) {
            return head;
        } 
        ListNode prev = null, cur = head, next = null, check = head;
        int len = 0;
        while (check != null) {
            check = check.next;
            len ++;
            if (len == k) {
                break;
            }
        }
        if (len == k) {
            while (len > 0) {
                next = cur.next;
                cur.next = prev;
                prev = cur;
                cur = next;
                len --;
            }
            if (next != null) {
                head.next = reverseKGroup(next, k);
            }
            return prev;
        } else {
            return head;
        }
    }
}
// @lc code=end

