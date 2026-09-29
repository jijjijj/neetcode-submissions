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
        if (!k) return head;
        
        ListNode fake(0, head);

        head = &fake;

        // loop it back
        while (head->next) head = head->next;
        head->next = fake.next;

        // f->1 2 3 4 h5 6<-fs, k=2
        // 5 6 1 2 3 4
        ListNode* slow = &fake;
        ListNode* fast = slow;

        while (k && fast->next) {
            --k;
            fast = fast->next;
        }

        while (fast->next != fake.next) {
            slow = slow->next;
            fast = fast->next;
        }

        head = slow->next;
        slow->next = nullptr;
        fast->next = fake.next;
        return head;
    }
};