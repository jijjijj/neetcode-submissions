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
        return search_dfs(word, 0, &root);
    }

private:
    struct Node {
        Node* children[26]{};
        bool ends = false;

        ~Node() {
            for (Node* c : children) delete c;
        }
    };

    bool search_dfs(const string& word, int i, const Node* node) {
        for (int j = i; j < word.size(); ++j) {
            const char ch = word[j];

            if (ch == '.') {
                for (Node* child : node->children) {
                    if (child && search_dfs(word, j + 1, child))
                        return true;
                }

                return false;
            } else if (!node->children[ch - 'a']) {
                return false;
            }
            node = node->children[ch - 'a'];
        }

        return node->ends;
    }

    Node root{};
};
