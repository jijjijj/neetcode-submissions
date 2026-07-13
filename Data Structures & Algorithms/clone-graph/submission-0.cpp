/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<int, Node*> mp;
        return copy(node, mp);
    }

private:
    Node* copy(Node* ref, std::unordered_map<int, Node*>& mp) {
        if (!ref) return nullptr;

        Node* node = new Node{ ref->val };
        mp[ref->val] = node;

        std::vector<Node*> nbrs = ref->neighbors;
        for (auto& neighbor : nbrs) {
            if (!neighbor) continue;
            neighbor = mp.contains(neighbor->val) ? mp[neighbor->val] : copy(neighbor, mp);
        }
        node->neighbors = std::move(nbrs);

        return node;
    }
};
