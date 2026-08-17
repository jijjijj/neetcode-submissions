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

        std::vector<int> dp(n, 999999);
        for (int i = 0; i < n; ++i) {
            auto* cur = &trie.root;
            int j = i;
            while (j < n && cur->children[s[j] - 'a']) {
                cur = cur->children[s[j] - 'a'];
                if (cur->ends) {
                    const int prev = i ? dp[i - 1] : 0;
                    dp[j] = std::min(prev, dp[j]);
                }
                ++j;
            }
            dp[i] = std::min(
                (i ? dp[i - 1] + 1 : 1), dp[i]);
            
            // std::cout << j << " " << cur->ends << std::endl;
            // std::cout << dp[i] << " "; 
        }

        return dp.back();
    }
};