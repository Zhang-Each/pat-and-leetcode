/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个升序链表
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
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode res = new ListNode();
        ListNode p = res;
        while (true) {
            int value = 100000, index = -1;
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] != null && lists[i].val < value) {
                    index = i;
                    value = lists[i].val;
                }
            }
            if (index == -1) {
                break;
            }
            ListNode newp = new ListNode(value);
            p.next = newp;
            p = p.next;
            lists[index] = lists[index].next;
        }
        return res.next;
    }
}
// @lc code=end

