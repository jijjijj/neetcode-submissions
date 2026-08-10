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
        ListNode* last = nullptr;
        ListNode* slow = head;
        ListNode* start = head;
        ListNode fake;
        ListNode* end = &fake;

        // ListNode* start = head;
        int cur = 0;
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = last;
            last = slow;
            slow = tmp;

            if (++cur == k) {
                cur = 0;
                end->next = last;
                end = start;
                start->next = slow;
                start = slow;

                int n = 0;
                ListNode* f = end;
                while (n < k && f) {f = f->next;++n;};
                if (!f) break;
            }
        }

        return fake.next;
    }
};
