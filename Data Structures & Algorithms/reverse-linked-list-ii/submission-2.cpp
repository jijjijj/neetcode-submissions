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
    // it I
    // it II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode fake(0, head);
        ListNode* start = &fake;
        ListNode* prev = nullptr;

        for (int i = 0; i < left; ++i) {
            prev = start;
            start = start->next;
        }

        ListNode* tail = start;
        for (int i = 0; i < right - left; ++i) {
            tail = tail->next;
        }

        ListNode* nxt = tail->next;
        tail->next = nullptr;
        prev->next = reverse(start);
        start->next = nxt;
        return fake.next;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};