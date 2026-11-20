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

        while (pp && qq) {
            pp = pp->parent;
            qq = qq->parent;
        }

        if (qq) {
            std::swap(pp, qq);
            std::swap(p, q);
        }

        while (pp) {
            pp = pp->parent;
            p = p->parent;
        }

        while (p != q) {
            p = p->parent;
            q = q->parent;
        }

        return p;
    }
};