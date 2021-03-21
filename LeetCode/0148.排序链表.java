/*
 * @lc app=leetcode.cn id=148 lang=java
 *
 * [148] 排序链表
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
    public ListNode sortList(ListNode head) {
        ListNode p = head;
        int len = 0, count = 0;
        while (p != null) {
            len ++;
            p = p.next;
        }
        if (len <= 1) {
            return head;
        }
        int[] nums = new int[len];
        p = head;
        for (int i = 0; i < len; i ++) {
            nums[i] = p.val;
            p = p.next;
        }
        Arrays.sort(nums);
        p = head;
        while (p != null) {
            p.val = nums[count++];
            p = p.next;
        }
        return head;
    }
}

// @lc code=end

