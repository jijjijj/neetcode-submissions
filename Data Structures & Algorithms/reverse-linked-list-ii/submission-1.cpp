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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fake(0, head);
        ListNode* start = &fake; // + 1 is actual start

        int count = right - left + 1;

        --left;
        while (left--) {
            start = start->next;
        }
        // f-><-1<-2 3

        ListNode* last = start;
        ListNode* ss = start->next;

        while (count--) {
            // std::cout << ss->val << " " << last->val << std::endl;

            ListNode* tmp = ss->next;
            ss->next = last;
            last = ss;
            ss = tmp;
        }

        start->next->next = ss;
        start->next = last;

        return fake.next;
    }
};