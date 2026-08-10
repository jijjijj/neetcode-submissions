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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        int i = 0;
        ListNode* cur = head;
        while (i < k && cur) {
            cur = cur->next;
            ++i;
        }

        if (i < k) return head;

        ListNode* last = nullptr;
        ListNode* rest = reverseKGroup(cur, k);
        ListNode* sent = cur;
        cur = head;
        while (cur != sent) {
            ListNode* tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        head->next = rest;

        return last;
    }
};
