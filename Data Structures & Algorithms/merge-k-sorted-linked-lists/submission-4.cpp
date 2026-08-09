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
        const auto comp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };

        std::priority_queue<ListNode*,
            std::vector<ListNode*>,
            decltype(comp)> q(comp);
        for (auto list : lists)
            if (list) q.push(list);

        ListNode fake;
        ListNode* last = &fake;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();

            last->next = node;
            last = node;

            if (node->next) q.push(node->next);
        }

        return fake.next;
    }
};
