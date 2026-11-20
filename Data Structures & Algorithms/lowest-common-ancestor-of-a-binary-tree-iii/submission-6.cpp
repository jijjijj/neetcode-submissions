/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* pp = p;
        Node* qq = q;

        while (pp != qq) {
            pp = pp ? pp->parent : q;
            qq = qq ? qq->parent : p;
        }

        return pp;
    }
};