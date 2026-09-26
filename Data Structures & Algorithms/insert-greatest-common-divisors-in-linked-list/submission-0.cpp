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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;

        while (cur && cur->next) {
            ListNode* node = new ListNode(
                mygcd(cur->val, cur->next->val));
            
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        return head;
    }

private:
    int mygcd(int a, int b) {
        while (a && b) {
            const int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};