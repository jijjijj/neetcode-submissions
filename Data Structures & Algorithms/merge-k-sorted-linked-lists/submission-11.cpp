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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeLists(const vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];

        const int mid = l + (r - l) / 2;
        ListNode* a = mergeLists(lists, l, mid);
        ListNode* b = mergeLists(lists, mid + 1, r);

        ListNode fake;
        ListNode* last = &fake;

        while (a && b) {
            if (a->val < b->val) {
                last->next = a;
                a = a->next;
            } else {
                last->next = b;
                b = b->next;
            }

            last = last->next;
        }

        if (a) {
            last->next = a;
        } else {
            last->next = b;
        }

        return fake.next;
    }
};