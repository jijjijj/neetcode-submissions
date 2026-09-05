class MyHashSet {
private:
    class BST {
        struct Node {
            int key{};
            Node* left{};
            Node* right{};
        };

    public:
        void add(int key) {
            root = add(root, key);
        }

        void remove(int key) {
            root = remove(root, key);
        }

        bool contains(int key) {
            return contains(root, key);
        }

    private:
        Node* add(Node* root, int key) {
            if (!root) return new Node{ .key = key };
            if (root->key == key) return root;

            if (key < root->key) {
                root->left = add(root->left, key);
            } else {
                root->right = add(root->right, key);
            }

            return root;
        }

        Node* remove(Node* root, int key) {
            if (!root) return nullptr;
            if (root->key == key) {
                Node* min = root->right;
                Node* left = root->left;
                
                if (!min) {
                    delete root;
                    return left;
                }

                while (min && min->left) min = min->left;
                root->key = min->key;
                root->right = remove(root->right, min->key);
            } else if (key < root->key) {
                root->left = remove(root->left, key);
            } else {
                root->right = remove(root->right, key);
            }
            
            return root;
        }

        bool contains(Node* root, int key) {
            if (!root) return false;
            if (root->key == key) return true;
            if (key < root->key) return contains(root->left, key);
            return contains(root->right, key);
        }

        Node* root{};
    };

public:
    MyHashSet() : buckets(10009) {}
    
    void add(int key) {
        buckets[hash(key)].add(key);
    }
    
    void remove(int key) {
        buckets[hash(key)].remove(key);
    }
    
    bool contains(int key) {
        return buckets[hash(key)].contains(key);
    }

private:
    int hash(int key) {
        return key % buckets.size();
    }

    std::vector<BST> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */