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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode fake(0, head);
        int n = 0;
        
        head = &fake;
        while (head->next) {
            ++n;
            head = head->next;
        }

        if (n) {
            k %= n;
            k = n - k;
        } else k = 0;

        // loop it
        head->next = fake.next;

        // 1 2 3 4 5 6, k=2: 5 6 1 2 3 4
        ListNode* cur = &fake;
        while (cur && k--) {
            cur = cur->next;
        }

        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};