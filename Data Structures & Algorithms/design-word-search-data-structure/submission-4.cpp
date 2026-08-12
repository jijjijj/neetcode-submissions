class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* node = &root;

        for (int i = 0; i < word.size(); ++i) {
            const int idx = word[i] - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new Node{};
            }

            node = node->children[idx];
        }

        node->ends = true;
    }
    
    bool search(string word) {
        return search_dfs(word, 0, root);
    }

private:
    struct Node {
        Node* children[26]{};
        bool ends = false;

        ~Node() {
            for (Node* c : children) delete c;
        }
    };

    bool search_dfs(const string& word, int i, const Node& node) {
        if (i >= word.size()) return node.ends;

        const char ch = word[i];

        if (ch == '.') {
            for (int j = 0; j < 26; ++j) {
                if (node.children[j] && search_dfs(word, i + 1, *node.children[j]))
                    return true;
            }

            return false;
        } else if (node.children[ch - 'a']) {
            return search_dfs(word, i + 1, *node.children[ch - 'a']);
        }

        return false;
    }

    Node root{};
};
