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
        if (lists.empty()) return nullptr;
        
        for (int i = 1; i < lists.size(); ++i) {
            lists[0] = mergeLists(lists[0], lists[i]);
        }

        return lists[0];
    }

private:
    ListNode* mergeLists(ListNode* a, ListNode* b) {
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