class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* node = &root;

        for (char c : word) {
            Node*& child = node[c - 'a'];
            if (!child) {
                child = new Node{};
            }

            node = child;
        }

        node->ends = true;
    }
    
    bool search(string word) {
        Node* node = &root;

        for (char c : word) {
            if (c == '.') {

            } else {

            }
        }
    }

private:
    struct Node {
        Node* children[26] = {};
        bool ends{};

        ~Node() {
            for (auto node : children) delete node;
        }
    };

    Node root{};
};
