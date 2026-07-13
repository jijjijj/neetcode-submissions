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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res{0};
        ListNode* last = &res;

        while (list1 && list2) {
            last->next = list1->val > list2->val ? list2 : list1;
            if (list1->val > list2->val) {
                list2 = list2->next;
            } else {
                list1 = list1->next;
            }

            last = last->next;
        }

        if (list1) {
            last->next = list1;
        } else {
            last->next = list2;
        }

        return res.next;
    }
};
