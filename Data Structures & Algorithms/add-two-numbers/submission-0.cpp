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
        ListNode* h1 = l1;
        ListNode* h2 = l2;

        ListNode* last1 = nullptr;
        ListNode* last2 = nullptr;
        int rem = 0;
        while (h1 && h2) {
            int n = h1->val + h2->val + rem;
            rem = 0;

            if (n >= 10) {
                rem = 1;
                n -= 10;
            }

            h1->val = h2->val = n;

            last1 = h1;
            last2 = h2;
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h2) {
            std::swap(h1, h2);
            std::swap(l1, l2);
            std::swap(last1, last2);
        }

        while (h1 && rem) {
            if (h1->val < 9) {
                ++h1->val;
                rem = 0;
                break;
            } else {
                h1->val = 0;
            }

            last1 = h1;
            h1 = h1->next;
        }

        if (rem) {
            last1->next = new ListNode{1, nullptr};
        }

        return l1;
    }
};
