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

        k %= std::max(1, n);

        // loop it
        head->next = fake.next;

        // 1 2 3 4 5 6, k=2: 5 6 1 2 3 4
        ListNode* cur = &fake;
        for (int i = 0; i < n - k; ++i) {
            cur = cur->next;
        }

        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};