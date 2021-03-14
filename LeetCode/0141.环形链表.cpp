/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        while (p != NULL) {
            if (p->val == 100001) {
                return true;
            }
            p->val = 100001;
            p = p->next;
        }
        return false;
    }
};
// @lc code=end

