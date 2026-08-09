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

        while (lists.size() != 1) {
            std::vector<ListNode*> nw;        
            for (int i = 1; i < lists.size(); i += 2) {
                nw.emplace_back(mergeLists(lists[i], lists[i - 1]));
            }
            if (lists.size() & 1) nw.emplace_back(lists.back());
            lists = std::move(nw);
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