class Trie {
public:
    struct Node {
        Node* children[26]{};
        bool ends{};

        Node() = default;
        Node(const Node&) = delete;
        Node& operator==(const Node&) = delete;
        ~Node() {
            for (const auto c : children)
                delete c;
        }
    };

    void add(const std::string& str) {
        Node* node = &root;

        for (int i = str.size() - 1; i >= 0; --i) {
            if (!node->children[str[i] - 'a']) {
                node->children[str[i] - 'a'] = new Node{};
            }

            node = node->children[str[i] - 'a'];
        }

        node->ends = true;
    }

    Node root;
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();

        Trie trie;
        for (const auto& word : wordDict) {
            trie.add(word);
        }

        std::vector<std::vector<std::string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; ++i) {
            auto* node = &trie.root;

            for (int j = i - 1; j >= 0; --j) {
                if (!node->children[s[j] - 'a']) break;
                node = node->children[s[j] - 'a'];
  
                if (node->ends) {
                    const std::string str = s.substr(j, i - j);
                    for (const auto& sen : dp[j]) {
                        if (sen.empty()) {
                            dp[i].emplace_back(str);
                        } else {
                            dp[i].emplace_back(sen + " " + str);
                        }
                    }
                }
            }
        }

        return dp.back();
    }
};