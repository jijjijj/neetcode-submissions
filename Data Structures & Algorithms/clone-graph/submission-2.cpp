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

        std::queue<Node*> q;
        q.push(node);
        mp[node] = new Node{ node->val };

        while (!q.empty()) {
            const auto v = q.front();
            q.pop();

            for (Node* nei : v->neighbors) {
                Node* copy = nullptr;
                if (!mp.contains(nei)) {
                    mp[nei] = new Node{ nei->val };
                    q.push(nei);
                }
                mp[v]->neighbors.emplace_back(mp[nei]);
            }
        }

        return mp[node];
    }

private:
    std::unordered_map<Node*, Node*> mp; // old -> new
};
