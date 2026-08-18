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

    Node root{};
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string prefix;

        Trie trie{};
        for (const auto& word : strs) trie.add(word);

        auto* cur = &trie.root;

        while (cur && !cur->ends) {
            int cnt = 0;
            int idx = 0;

            for (int i = 0; i < 26; ++i) {
                if (cur->children[i]) {
                    ++cnt;
                    idx = i;
                }
            }

            if (cnt > 1 || !cnt) break;

            prefix += ('a' + idx);
            cur = cur->children[idx];
        }

        return prefix;
    }
};