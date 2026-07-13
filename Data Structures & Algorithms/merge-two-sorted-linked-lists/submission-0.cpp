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
        ListNode* res = new ListNode;
        ListNode* last = res;

        while (list1 || list2) {
            if (list1 && list2) {
                last->next = list1->val > list2->val ? list2 : list1;
                if (list1->val > list2->val) {
                    list2 = list2->next;
                } else {
                    list1 = list1->next;
                }
            } else if (list1) {
                last->next = list1;
                list1 = list1->next;
            }
            else {
                last->next = list2;
                list2 = list2->next;
            }

            last = last->next;
        }

        return res->next;
    }
};
