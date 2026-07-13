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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* last = head;
        ListNode fake(0, nullptr);
        ListNode* attach_to = &fake;

        int c = 0;

        while (c < k && curr) {
            if (c < k - 1) {
                ++c;
                curr = curr->next;
            } else {
                // std::cout << "at " << curr->val << std::endl;
                c = 0;
                ListNode* tmp = curr->next;
                curr->next = nullptr;
                attach_to->next = reverseList(last);
                attach_to = last;
                last = tmp;
                curr = last;
            }
        }

        attach_to->next = last;

        return fake.next;
    }

private:
    ListNode* reverseList(ListNode* head) const {
        // ListNode fake(0, nullptr);

        ListNode* last = head;
        head = head->next;
        last->next = nullptr;

        while (head) {
            ListNode* tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }

        return last;
    }
};
