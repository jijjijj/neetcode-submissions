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
        std::unordered_set<int> vis;

        while (p) {
            vis.emplace(p->val);
            p = p->parent;
        }

        while (q) {
            if (vis.contains(q->val)) return q;
            q = q->parent;
        }

        return nullptr;
    }
};