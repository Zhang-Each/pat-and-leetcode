/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.19%)
 * Likes:    5454
 * Dislikes: 0
 * Total Accepted:    666.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode;
        ListNode* p = res, q;
        int carryOut = 0;
        while (l1 != NULL || l2 != NULL || carryOut != 0) {
            ListNode* q = new ListNode;
            if (l1 != NULL) {
                carryOut += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                carryOut += l2->val;
                l2 = l2->next;
            }
            q->val = carryOut % 10;
            carryOut /= 10;
            p->next = q;
            p = p->next;
        }
        return res->next;
    }
};
// @lc code=end

