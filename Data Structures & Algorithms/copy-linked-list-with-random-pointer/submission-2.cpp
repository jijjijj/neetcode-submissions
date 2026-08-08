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
        mp[nullptr] = nullptr;
        if (mp.contains(head)) return mp[head];

        Node* copy = new Node{ head->val };
        mp[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = mp[head->random];

        return copy;
    }

private:
    std::unordered_map<Node*, Node*> mp; // old->new
};
