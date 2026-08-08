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
        return rec(head, n) ? head->next : head;
    }

private:
    int rec(ListNode* head, int n) {
        if (!head) return 1;

        const int level = rec(head->next, n);
        if (!level) return 0;

        if (level == n + 1) {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            delete tmp;
            return 0;
        } else {
            return level + 1;
        }
    }
};
