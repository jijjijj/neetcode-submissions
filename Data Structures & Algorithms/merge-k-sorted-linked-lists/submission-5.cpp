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
        ListNode fake;
        ListNode* last = &fake;
        int done = 0;

        while (true) {
            int best = -1;
            int i = 0;
            
            for (; i < lists.size(); ++i) {
                if (lists[i] && (best == -1 ||
                    lists[i]->val < lists[best]->val)) {
                    best = i;
                }
            }

            if (best == -1) break;

            last->next = lists[best];
            last = last->next;

            lists[best] = last->next;
        }

        return fake.next;
    }
};
