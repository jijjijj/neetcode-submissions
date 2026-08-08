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

        Node* start = head;

        while (start) {
            if (!mp.contains(start)) {
                mp[start] = new Node{ 0 };
            }
            mp[start]->val = start->val;
            if (start->next && !mp.contains(start->next)) {
                mp[start->next] = new Node{ 0 };
            }
            mp[start]->next = mp[start->next];
            if (start->random && !mp.contains(start->random)) {
                mp[start->random] = new Node{ 0 };
            }
            mp[start]->random = mp[start->random];
            start = start->next;
        }

        return mp[head];
    }
};
