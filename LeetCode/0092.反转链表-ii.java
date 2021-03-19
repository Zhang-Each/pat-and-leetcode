/*
 * @lc app=leetcode.cn id=92 lang=java
 *
 * [92] 反转链表 II
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
    // 链表题最好加一个空的头部，写起来比较方便
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (left == right || head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode s = dummy;
        int count = 1;
        while (count < left) {
            s = s.next;
            count += 1;
        }
        ListNode prev = null, cur = s.next;
        for (int i = left; i <= right; i ++) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        // 这个时候s.next指向的还是left，而left已经被反转了，因此可以直接让left指向这个停留在末尾的cur
        s.next.next = cur;
        //prev 此时位于right位置，因此要让s.next指向right
        s.next = prev;
        return dummy.next;
    }
}
// @lc code=end

