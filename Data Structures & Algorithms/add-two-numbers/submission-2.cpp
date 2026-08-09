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
        return rec(l1, l2, 0);
    }

private:
    ListNode* rec(ListNode* a, ListNode* b, int carry) {
        if (!a && b) std::swap(a, b);

        if (a && b) {
            const int sum = a->val + b->val + carry;
            a->val = b->val = (sum % 10);
            b->next = a->next = rec(a->next, b->next, sum > 9);
            return a;
        } else if (a) {
            const int sum = a->val + carry;
            a->val = (sum % 10);
            a->next = rec(a->next, nullptr, sum > 9);
            return a;
        } else if (carry) {
            return new ListNode{ carry };
        }

        return nullptr;
    }
};
