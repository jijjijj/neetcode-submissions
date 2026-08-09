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

        const int vala = a ? a->val : 0;
        const int valb = b ? b->val : 0;
        const int sum = vala + valb + carry;
        const int nval = sum % 10;
        const int ncarry = sum > 9;

        if (a && b) {
            a->val = b->val = nval;
            b->next = a->next = rec(a->next, b->next, ncarry);
            return a;
        } else if (a) {
            a->val = nval;
            a->next = rec(a->next, nullptr, ncarry);
            return a;
        } else if (carry) {
            return new ListNode{ carry };
        }

        return nullptr;
    }
};
