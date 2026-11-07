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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* last = nullptr;
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = last;
            last = slow;
            slow = tmp;
        }

        while (last) {
            if (head->val != last->val) return false;
            head = head->next;
            last = last->next;
        }

        return true;
    }
};