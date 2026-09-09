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

        for (int i = 0; i < str.size(); ++i) {
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
        Trie trie;
        for (const auto& word : wordDict) {
            trie.add(word);
        }

        dfs(0, trie, s);

        return res;
    }

private:
    void dfs(int i, const Trie& trie, const std::string& s) {
        if (i == s.size()) {
            // final
            std::stringstream ss;
            for (int j = 0; j < cur.size(); ++j) {
                if (j) ss << " ";
                ss << cur[j];
            }
            res.emplace_back(ss.str());
            return;
        }

        auto node = &trie.root;

        for (int j = i; j < s.size(); ++j) {
            if (!node->children[s[j] - 'a']) break;
            node = node->children[s[j] - 'a'];
            if (node->ends) {
                cur.emplace_back(s.substr(i, j - i + 1));
                dfs(j + 1, trie, s);
                cur.pop_back();
            }
        }
    }

    std::vector<std::string> res;
    std::vector<std::string> cur;
};