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
        if (!node) return nullptr;
        if (mp.contains(node)) return mp[node];
        
        mp[node] = new Node{ node->val };

        for (Node* nei : node->neighbors) {
            mp[node]->neighbors.emplace_back(
                cloneGraph(nei));
        }

        return mp[node];
    }

private:
    std::unordered_map<Node*, Node*> mp; // old -> new
};
