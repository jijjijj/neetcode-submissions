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
    void reorderList(ListNode* head) {
        reorder(head, head->next);
    }

private:
    ListNode* reorder(ListNode* root, ListNode* cur) {
        if (!cur) return root;

        root = reorder(root, cur->next);
        if (!root) return nullptr;

        ListNode* tmp = nullptr;
        if (root->next == cur || root == cur) {
            cur->next = nullptr;
        } else {
            tmp = root->next;
            root->next = cur;
            cur->next = tmp;
        }

        return tmp;
    }
};
