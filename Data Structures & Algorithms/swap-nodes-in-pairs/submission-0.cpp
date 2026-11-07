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
    ListNode* swapPairs(ListNode* head) {
        ListNode fake(0, head);
        ListNode* last = &fake;

        while (head && head->next) {
            ListNode* next = head->next;
            ListNode* tmp = next->next;
            last->next = next;
            next->next = head;
            head->next = tmp;
            last = head;
            head = tmp;
        }

        return fake.next;
    }
};
