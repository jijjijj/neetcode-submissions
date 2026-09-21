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
    // +rec I
    // rec II
    // +it I
    // +it II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverse(head, right).first;
        }

        head->next = reverseBetween(head->next,
            left - 1, right - 1);

        return head;
    }

private:
    std::pair<ListNode*, ListNode*> reverse(ListNode* head, int n) {
        if (n == 1) {
            // new head, new end
            return { head, head->next };
        }

        const auto data = reverse(head->next, n - 1);
        head->next->next = head;
        head->next = data.second;

        return data;
    }
};