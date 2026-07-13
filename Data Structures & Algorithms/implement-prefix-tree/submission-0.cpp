class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* node = &root;

        for (char c : word) {
            Node*& child = node->children[c - 'a'];

            if (!child) {
                node->children[c - 'a'] = new Node{};
            }

            node = child;
        }

        node->ends = true;
    }
    
    bool search(string word) {
        Node* node = &root;

        for (char c : word) {
            Node*& child = node->children[c - 'a'];

            if (!child) {
                return false;
            }

            node = child;
        }

        return node->ends;
    }
    
    bool startsWith(string prefix) {
        Node* node = &root;

        for (char c : prefix) {
            Node*& child = node->children[c - 'a'];

            if (!child) {
                return false;
            }

            node = child;
        }

        return true;
    }

private:
    struct Node {
        Node* children[26] = {};
        bool ends = false;

        ~Node() {
            for (Node* child : children) delete child; 
        }
    };

    Node root{};
};
