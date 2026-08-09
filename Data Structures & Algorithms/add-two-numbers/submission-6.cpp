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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode fake;
        ListNode* cur = &fake;
        int carry = 0;

        while (l1 || l2 || carry) {
            const int val1 = l1 ? l1->val : 0;
            const int val2 = l2 ? l2->val : 0;

            const int sum = val1 + val2 + carry;
            const int digit = sum % 10;
            
            carry = sum > 9;

            cur->next = new ListNode{ digit };
            cur = cur->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return fake.next;
    }
};
