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
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* last = nullptr;
        int carry = 0;
        while (head1 && head2) {
            const int dig = head1->val + head2->val + carry;
            head1->val = head2->val = (dig % 10);
            carry = (dig > 9);
            last = head1;
            head1 = head1->next;
            head2 = head2->next;
        }

        ListNode* ans = head2 ? l2 : l1;

        while (head1) {
            head1->val += carry;
            carry = (head1->val > 9);
            head1->val %= 10;
            last = head1;
            head1 = head1->next;
        }

        while (head2) {
            head2->val += carry;
            carry = (head2->val > 9);
            head2->val %= 10;
            last = head2;
            head2 = head2->next;
        }

        if (carry) {
            last->next = new ListNode{ carry };
        }

        return ans;
    }
};
