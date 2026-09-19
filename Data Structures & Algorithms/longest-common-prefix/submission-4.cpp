class Trie {
public:
    struct Node {
        Node* children[26]{};
        bool ends{};

        ~Node() {
            for (Node* c : children) delete c;
        }
    };

    void add(const std::string& str) {
        Node* cur = &root;

        for (int i = 0; i < str.size(); ++i) {
            const int idx = str[i] - 'a';

            if (!cur->children[idx]) {
                cur->children[idx] = new Node{};
            }

            cur = cur->children[idx];
        }

        cur->ends = true;
    }

    size_t lcp(const std::string& w, size_t prefix) {
        Node* node = &root;

        size_t i = 0;
        for (; i < std::min(w.size(), prefix); ++i) {
            node = node->children[w[i] - 'a'];
            if (!node) return i;
        }
        return i;
    } 

    Node root{};
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie{};

        trie.add(strs[0]);
        size_t prefix = strs[0].size();

        for (int i = 1; i < strs.size(); ++i) {
            prefix = trie.lcp(strs[i], prefix);
        }

        return strs[0].substr(0, prefix);
    }
};