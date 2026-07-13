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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode fake(0, head);
        ListNode* start = &fake;
        ListNode* fast = &fake;

        ++n;
        while (n--) {
            fast = fast->next;
        }

        ListNode* last = &fake;
        while (fast) {
            last = head;
            head = head->next;
            fast = fast->next;
        }

        last->next = head->next;

        return fake.next;
    }
};
