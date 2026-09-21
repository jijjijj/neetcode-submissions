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
    // rec I
    // rec II
    // +it I
    // it II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fake(0, head);
        ListNode* start = &fake;
        ListNode* prev = nullptr;

        for (int i = 0; i < left; ++i) {
            prev = start;
            start = start->next;
        }

        // l = 1, r = 4
        // p                   s    t 
        // f -> 1 <- 2 <- 3 <- 4 -> 5 -> <end>
        ListNode* tail = start->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* nxt = tail->next;
            tail->next = start;
            start = tail;
            tail = nxt;
        }

        prev->next->next = tail;
        prev->next = start;

        return fake.next;
    }
};