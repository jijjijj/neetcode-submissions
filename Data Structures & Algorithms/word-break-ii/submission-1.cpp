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
        const int n = s.size();

        // Trie trie;
        // for (const auto& word : wordDict) {
        //     trie.add(word);
        // }
        std::unordered_set<std::string> hs{
            wordDict.begin(), wordDict.end()
        };
        std::vector<std::vector<std::string>> dp(n + 1);
        dp[0] = {""};
        // dfs(0, trie, s);

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                const std::string str = s.substr(j, i - j);

                if (hs.contains(str)) {
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

private:
    // void dfs(int i, const Trie& trie, const std::string& s) {
    //     if (i == s.size()) {
    //         // final
    //         std::stringstream ss;
    //         for (int j = 0; j < cur.size(); ++j) {
    //             if (j) ss << " ";
    //             ss << cur[j];
    //         }
    //         res.emplace_back(ss.str());
    //         return;
    //     }

    //     auto node = &trie.root;

    //     for (int j = i; j < s.size(); ++j) {
    //         if (!node->children[s[j] - 'a']) break;
    //         node = node->children[s[j] - 'a'];
    //         if (node->ends) {
    //             cur.emplace_back(s.substr(i, j - i + 1));
    //             dfs(j + 1, trie, s);
    //             cur.pop_back();
    //         }
    //     }
    // }

    std::vector<std::string> res;
    std::vector<std::string> cur;
};