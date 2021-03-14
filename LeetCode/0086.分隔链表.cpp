/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* a = new ListNode(0); 
        ListNode* b = new ListNode(0);
        ListNode *p = a, *q = b;
        while (head != NULL) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = NULL;
        p->next = b->next;
        return a->next;
    }
};
// @lc code=end