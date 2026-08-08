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
        ListNode* mid = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* last = nullptr;
        fast = mid;

        while (fast) {
            ListNode* tmp = fast->next;
            fast->next = last;
            last = fast;
            fast = tmp;
        }

        // 0, 1, [NULL <- 2 <- 3] <- 4 = last

        fast = head;
        while (fast->next != last && fast != last) {
            ListNode* tmp = fast->next;
            fast->next = last;
            ListNode* tmp2 = last->next;
            last->next = tmp;
            last = tmp2;
            fast = tmp;
        }
    }
};
