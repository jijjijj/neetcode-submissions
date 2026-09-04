class MyHashMap {
    struct Node {
        int key{};
        int val{};
        Node* next{};
    };

public:
    MyHashMap() : buckets(1000) {
        for (int i = 0; i < buckets.size(); ++i) {
            buckets[i] = new Node{};
        }
    }
    
    void put(int key, int value) {
        const int k = key % buckets.size();

        Node* node = buckets[k];

        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                break;
            }

            node = node->next;
        }

        node->next = new Node{ .key = key, .val = value };
    }
    
    int get(int key) {
        const int k = key % buckets.size();
        
        Node* node = buckets[k];

        while (node->next) {
            if (node->next->key == key) {
                return node->next->val;
            }

            node = node->next;
        }

        return -1;
    }
    
    void remove(int key) {
        const int k = key % buckets.size();

        Node* node = buckets[k];
        
        while (node->next) {
            if (node->next->key == key) {
                Node* tmp = node->next;
                node->next = node->next->next;
                delete tmp;
                break;
            }

            node = node->next;
        }
    }

private:
    std::vector<Node*> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */