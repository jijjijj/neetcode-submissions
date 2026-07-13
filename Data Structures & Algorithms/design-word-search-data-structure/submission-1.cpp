class WordDictionary {
    struct Node {
        Node* children[26] = {};
        bool ends{};

        ~Node() {
            for (auto node : children) delete node;
        }
    };

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* node = &root;

        for (char c : word) {
            Node*& child = node->children[c - 'a'];
            if (!child) {
                child = new Node{};
            }

            node = child;
        }

        node->ends = true;
    }
    
    bool search(string word) {
        return search(word, &root);
    }

private:
    bool search(string_view word, Node* start) {
        // std::cout << std::string{ word } << " " << start->ends << std::endl;
        Node* node = start;

        for (size_t i = 0; i < word.size(); ++i) {
            const char c = word[i];
            if (c == '.') {
                bool result = false;

                for (char t = 0; t < 26; ++t) {
                    if (!node->children[t]) continue;

                    if (search(word.substr(i + 1), node->children[t])) return true;
                }

                return false;
            } else if (node->children[c - 'a']) {
                node = node->children[c - 'a'];
            } else {
                return false;
            }
        }

        return node->ends;
    }

    Node root{};
};
