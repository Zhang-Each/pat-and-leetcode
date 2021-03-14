/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* p = head;
        while(p != NULL) {
            if(p->val == 100001) {
                return p;
            }
            p->val = 100001;
            p = p->next;
        }
        return NULL;
    }
};
// @lc code=end

