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
    bool isPalindrome(ListNode* head) {
        cur = head;

        return is(head);
    }

private:
    bool is(ListNode* node) {
        if (node) {
            if (!is(node->next)) return false;
            if (node->val != cur->val) return false;

            cur = cur->next;
        }

        return true;
    }
    ListNode* cur = nullptr;
};