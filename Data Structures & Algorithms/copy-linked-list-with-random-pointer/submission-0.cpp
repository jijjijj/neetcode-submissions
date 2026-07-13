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
        Node result{0};

        std::unordered_map<Node*, Node*> orig_to_copy;

        Node* orig = head;
        Node* copy = &result;
        while (orig) {
            copy->next = new Node{orig->val};
            copy = copy->next;
            orig_to_copy[orig] = copy;
            orig = orig->next;
        }

        orig = head;
        copy = result.next;

        while (orig) {
            if (orig->random) {
                copy->random = orig_to_copy[orig->random];
            }

            copy = copy->next;
            orig = orig->next;
        }

        return result.next; 
    }
};
