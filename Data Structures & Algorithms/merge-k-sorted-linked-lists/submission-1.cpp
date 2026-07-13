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
private:
    struct Val {
        int val{};
        size_t ind{};

        bool operator>(const Val& b) const {
            return val > b.val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode fake(0, nullptr);
        ListNode* last = &fake;

        std::priority_queue<Val, std::vector<Val>,
            std::greater<Val>> q;

        for (size_t i = 0; i < lists.size(); ++i) {
            q.push(Val{ .val = lists[i]->val, .ind = i });
        }

        while (!q.empty()) {
            Val v = q.top();
            q.pop();

            last->next = lists[v.ind];
            last = last->next;
            lists[v.ind] = lists[v.ind]->next;

            if (lists[v.ind]) {
                q.push(Val{
                    .val = lists[v.ind]->val,
                    .ind = v.ind
                });
            }
        }

        return fake.next;
    }
};
