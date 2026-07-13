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
        ListNode fake(0, nullptr);
        ListNode* last = &fake;

        const auto cmp = [](const ListNode* a, const ListNode* b) {
            if (!a) return false;
            if (!b) return true;
            
            return a->val > b->val;
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>,
            decltype(cmp)> q(lists.begin(), lists.end());

        while (!q.empty()) {
            ListNode* v = q.top();
            q.pop();

            if (v) {
                last->next = v;
                last = last->next;

                q.push(v->next);
            }
        }

        return fake.next;
    }
};
