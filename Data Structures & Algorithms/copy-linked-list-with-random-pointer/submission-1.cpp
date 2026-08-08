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
        std::unordered_map<Node*, Node*> mp; // old->new

        Node fake2(0);
        Node* cur1 = head;
        Node* cur2 = &fake2;

        while (cur1) {
            Node* node = new Node{ cur1->val };
            mp[cur1] = node;
            cur2->next = node;
            cur2 = node;
            cur1 = cur1->next;
        }

        cur1 = head;
        cur2 = fake2.next;

        while (cur1) {
            cur2->random = mp[cur1->random];
            cur2 = cur2->next;
            cur1 = cur1->next;
        }

        return fake2.next;
    }
};
