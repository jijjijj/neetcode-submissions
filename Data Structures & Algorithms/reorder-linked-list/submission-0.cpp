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
    void reorderList(ListNode* head) {
        ListNode* start = head;
        ListNode* mid = head;
        ListNode* res = start;

        while (head && head->next) {
            mid = mid->next;
            head = head->next->next;
        }

        // std::cout << mid->val << std::flush;

        head = mid;
        mid = mid->next;
        ListNode* m = head;
        while (mid) {
            ListNode* temp = mid->next;
            mid->next = head;
            head = mid;
            mid = temp;
        }

        // ListNode* s = start;
        // while (s) {
        //     std::cout << s->val << " ";
            
        //     if (s->next != m) s = s->next;
        //     else break;
        // }

        while (m != head) {
            ListNode* temp = start->next;
            ListNode* temp2 = head->next;
            start->next = head;
            head->next = temp;
            start = temp;
            head = temp2;
        } 
        (head)->next = nullptr;
    }
};
