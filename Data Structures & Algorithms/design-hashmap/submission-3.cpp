class MyHashMap {
    struct Node {
        int key{};
        int val{};
        Node* next{};
    };

public:
    MyHashMap() : buckets(1009) {}
    MyHashMap(const MyHashMap&) = delete;
    MyHashMap& operator=(const MyHashMap&) = delete;
    ~MyHashMap() {
        for (const auto& bucket : buckets) {
            Node* node = bucket.next;
            while (node) {
                Node* nxt = node->next;
                delete node;
                node = nxt;
            }
        }
    }
    
    void put(int key, int value) {
        if (count / static_cast<float>(buckets.size()) > 0.75f) {
            resize(2 * buckets.size());
        }
        
        const unsigned int k = h(key);

        Node* node = &buckets[k];

        while (node->next) {
            if (node->next->key == key) {
                node->next->val = value;
                return;
            }

            node = node->next;
        }

        ++count;
        node->next = new Node{ .key = key, .val = value };
    }
    
    int get(int key) {
        const unsigned int k = h(key);
        
        Node* node = &buckets[k];

        while (node->next) {
            if (node->next->key == key) {
                return node->next->val;
            }

            node = node->next;
        }

        return -1;
    }
    
    void remove(int key) {
        const unsigned int k = h(key);

        Node* node = &buckets[k];
        
        while (node->next) {
            if (node->next->key == key) {
                Node* tmp = node->next;
                node->next = node->next->next;
                delete tmp;
                --count;
                break;
            }

            node = node->next;
        }
    }

private:
    unsigned int h(unsigned key) {
        unsigned int hash = 5381;
        
        hash = ((hash << 5) + hash) + ((key) & 0xFFu);
        hash = ((hash << 5) + hash) + ((key << 8) & 0xFF);
        hash = ((hash << 5) + hash) + ((key << 16) & 0xFFu);
        hash = ((hash << 5) + hash) + ((key << 24) & 0xFFu);

        return hash % buckets.size();
    }

    void resize(int new_size) {
        std::vector<Node> bs(new_size);

        std::swap(bs, buckets);

        for (const auto& bucket : bs) {
            Node* node = bucket.next;

            while (node) {
                Node* nxt = node->next;
                node->next = nullptr;

                const unsigned int k = h(node->key);
                
                Node* b = &buckets[k];

                while (b->next) {
                    b = b->next;
                }

                b->next = node;

                node = nxt;
            }
        }
    }

    std::vector<Node> buckets;
    int count{};
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */