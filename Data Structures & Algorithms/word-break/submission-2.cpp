class Trie {
public:
    struct Node {
        std::unordered_map<char, Node*> _children;
        bool is_word = false;
    };

    void insert(const std::string& word) {
        Node* node = &_root;

        for (int i = 0; i < word.size(); ++i) {
            if (!node->_children[word[i]]) {
                node->_children[word[i]] = new Node{};
            }

            node = node->_children[word[i]];
        }

        node->is_word = true;
    }

    bool search(const std::string& str, int i, int j) {
        Node* node = &_root;

        for (; i < j; ++i) {
            if (!node->_children[str[i]]) return false;

            node = node->_children[str[i]];
        }

        return node->is_word;
    }

    Node* get_root() {
        return &_root;
    }

private:
    Node _root;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        std::vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        Trie trie{};

        for (const auto& word : words) trie.insert(word);

        for (int i = 1; i <= s.size(); ++i) {
            if (!dp[i - 1]) continue;

            auto* node = trie.get_root();

            for (int j = i - 1; j < s.size(); ++j) {
                if (!node->_children[s[j]]) break;

                node = node->_children[s[j]];

                if (node->is_word) {
                    dp[j + 1] = true;
                    // std::cout << j << " ";
                }
            }
        }

        return dp.back();
    }
};
