class Trie {
public:
    struct Node {
        Node* children[26]{};
        bool ends{};

        ~Node() {
            for (Node* c : children) delete c;
        }
    };

    void add(const std::string& s) {
        Node* cur = &root;

        for (int i = 0; i < s.size(); ++i) {
            const int idx = s[i] - 'a';

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
    int minExtraChar(string s, vector<string>& dictionary) {
        const size_t n = s.size();
        Trie trie;

        for (const auto& str : dictionary) trie.add(str);

        std::vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1];
            auto* cur = &trie.root;
            for (int j = i; j < n; ++j) {
                if (cur->children[s[j] - 'a']) {
                    cur = cur->children[s[j] - 'a'];
                    if (cur->ends) {
                        dp[i] = std::min(dp[i], dp[j + 1]);
                    }
                } else break;
            }
        }

        return dp.front();
    }
};