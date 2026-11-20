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
        std::unordered_set<Node*> vis;

        while (p) {
            vis.emplace(p);
            p = p->parent;
        }

        while (q) {
            if (vis.contains(q)) return q;
            q = q->parent;
        }

        return nullptr;
    }
};