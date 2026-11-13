class Trie {
private:
    struct Node {
        Node* children[26]{};
        bool end = false;

        ~Node() {
            for (Node* child : children)
                delete child;
        }
    };

public:
    void add(const std::string& w) {
        Node* cur = &root;

        for (int i = 0; i < w.size(); ++i) {
            const int ind = w[i] - 'a';
            if (!cur->children[ind]) {
                cur->children[ind] = new Node{};
            }

            cur = cur->children[ind];
        }

        cur->end = true;
    }

    const Node* get_root() const {
        return &root;
    }

private:
    Node root{};
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie{};

        for (const auto& w : wordDict) trie.add(w);

        const int n = s.size();
        std::vector<bool> dp(n + 1);
        dp[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            const auto* cur = trie.get_root();

            // 0123|4
            // _abc|+

            int j = i;
            while (cur) {
                if (cur->end && dp[j]) {
                    dp[i] = true;
                    break;
                }

                if (j >= n) break;

                const int idx = s[j] - 'a';
                if (!cur->children[idx]) break;

                ++j;
                cur = cur->children[idx];
            }
        }

        return dp[0];
    }
};
