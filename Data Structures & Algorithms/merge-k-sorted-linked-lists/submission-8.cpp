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
        while (lists.size() > 1) {
            std::vector<ListNode*> ls;

            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;

                ls.emplace_back(merge(l1, l2));
            }

            lists = std::move(ls);
        }

        return lists.empty() ? nullptr : lists[0];
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) const {
        ListNode fake(0, nullptr);
        ListNode* last = &fake;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                last->next = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                l2 = l2->next;
            }

            last = last->next;
        }

        if (l1) last->next = l1;
        if (l2) last->next = l2;

        return fake.next;
    }
};
