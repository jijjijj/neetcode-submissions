class LRUCache {
    struct Node {
        Node* left{};
        Node* right{};
        int val = 0;
    };

public:
    LRUCache(int capacity) : cap{ capacity } {
        root.right = &end;
        end.left = &root;
    }
    
    int get(int key) {
        if (const auto it = latest.find(key);
            it != latest.end()) {
            const int value = it->second.first;
            update_key(key, value);
            return value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        const int size = latest.size();
        update_key(key, value);

        if (latest.size() > cap) {
            latest.erase(root.right->val);
            Node* node = root.right;
            root.right = node->right;
            node->right->left = &root;
            delete node;
        }
    }

private:
    void update_key(int key, int value) {
        Node* node = nullptr;
        if (const auto it = latest.find(key);
            it != latest.end()) {
            node = it->second.second;
            node->left->right = node->right;
            node->right->left = node->left;
        } else {
            node = new Node{ .val = key };
        }

        node->right = &end;
        node->left = end.left;
        end.left->right = node;
        end.left = node;
        latest[key] = std::pair{ value, node };
    }

    Node root{};
    Node end{};
    std::unordered_map<int,
        std::pair<int, Node*>> latest;
    int cap{};
};
