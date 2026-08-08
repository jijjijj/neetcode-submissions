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
        ListNode* slow = head;
        ListNode* fast = head;

        // 1 2 l=3 s=4 5 f=null, n = 2

        // f.n=1 l=2 s=3 f=null, n = 1

        while (n--) {
            fast = fast->next;
        }

        ListNode fake(0, slow);
        ListNode* last = &fake;
        while (fast) {
            last = slow;
            slow = slow->next;
            fast = fast->next;
        }

        last->next = slow->next;
        delete slow;

        return fake.next;
    }
};
