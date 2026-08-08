/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* l1 = head;

        while (l1) {
            Node* tmp = l1->next;
            l1->next = new Node{ l1->val };
            l1->next->next = tmp;
            l1 = tmp;
        }

        l1 = head;
        
        Node fake(0);
        Node* last = &fake;

        while (l1) {
            Node* l2 = l1->next;
            if (l1->random) l2->random = l1->random->next;
            last->next = l2;
            l1 = l2->next;
            last = l2;
        }

        return fake.next;
    }
};
