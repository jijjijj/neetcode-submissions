class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
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
        Node* node = &root;

        for (int i = 0; i < word.size(); ++i) {
            const int idx = word[i] - 'a';

            if (!node->children[idx])
                return false;

            node = node->children[idx];
        }

        return node->ends;
    }
    
    bool startsWith(string prefix) {
        Node* node = &root;

        for (int i = 0; i < prefix.size(); ++i) {
            const int idx = prefix[i] - 'a';

            if (!node->children[idx])
                return false;

            node = node->children[idx];
        }

        return true;
    }

private:
    struct Node {
        Node* children[26]{};
        bool ends{};

        ~Node() {
            for (Node* child : children) delete child;
        }
    };

    Node root{};
};
