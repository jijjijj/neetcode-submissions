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
    ListNode* partition(ListNode* head, int x) {
        ListNode smaller;
        ListNode bigger;

        ListNode* prev_smaller = &smaller;
        ListNode* prev_bigger = &bigger;

        ListNode* cur = head;

        while (cur) {
            if (cur->val < x) {
                prev_smaller->next = cur;
                prev_smaller = cur;
            } else {
                prev_bigger->next = cur;
                prev_bigger = cur;
            }

            cur = cur->next;
        }

        prev_smaller->next = bigger.next;
        prev_bigger->next = nullptr;

        return smaller.next;
    }
};