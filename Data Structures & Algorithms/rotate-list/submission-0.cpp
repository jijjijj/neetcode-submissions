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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode fake(0, head);
        int n = 0;

        head = &fake;
        while (head->next) {
            ++n;
            head = head->next;
        }

        if (!n) return nullptr;
        // std::cout << k << " " << n;

        k = k % n;
        if (!k) return fake.next;

        k = n - k;
        ListNode* cur = &fake;

        // <-1<-2(3)<-3(2)<-4(1)<-cur 5 6<-head, k = 2
        // 4 3 2 1<-cur 5 6<-head
        // 5 6 1 2 3 4
        // 1 2 3 4<-5 6
        while (cur && k) {
            --k;

            cur = cur->next;
        }

        // cur->1<-head

        ListNode* tmp = fake.next;
        fake.next = cur->next;
        head->next = tmp;
        cur->next = nullptr;
        return fake.next;
    }
};