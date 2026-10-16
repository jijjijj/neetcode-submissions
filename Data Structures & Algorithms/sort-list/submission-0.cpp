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
    ListNode* sortList(ListNode* head) {
        int size = 1;

        ListNode fake(0, head);

        int n = 0;
        while (head) {
            ++n;
            head = head->next;
        }

        while (size < n) {
            ListNode* prev = &fake;
            ListNode* cur = prev->next;

            while (cur) {
                ListNode* left = cur;
                ListNode* right = left;
                int j = size;
                while (right->next && --j) right = right->next;

                ListNode* tmp = right->next;
                right->next = nullptr;
                right = tmp;

                if (right) {
                    j = size;
                    cur = right;
                    while (cur->next && --j) cur = cur->next;

                    tmp = cur->next;
                    cur->next = nullptr;
                    cur = tmp;
                } else cur = nullptr;

                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }

            size <<= 1;
        }

        return fake.next;
    }

private:
    ListNode* split(ListNode* head, int n) {
        if (!head) return nullptr;

        while (head->next && --n) head = head->next;

        ListNode* tmp = head->next;
        head->next = nullptr;
        return tmp;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode fake;
        ListNode* cur = &fake;

        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }

            cur = cur->next;
        }

        cur->next = (left ? left : right);

        return fake.next;
    }
};