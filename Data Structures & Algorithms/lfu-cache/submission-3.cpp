class LinkedList {
public:
    struct Node {
        int val{};
        int key{};
        int freq{};

        Node* next{};
        Node* prev{};
    };

    LinkedList() {
        start.next = &end;
        end.prev = &start;
    }

    Node* pop_start() {
        if (empty()) return nullptr;

        return erase(start.next);
    }

    Node* erase(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --count;
        return node;
    }

    void push_end(Node* node) {
        node->next = &end;
        node->prev = end.prev;
        end.prev->next = node;
        end.prev = node;
        ++count;
    }

    bool empty() {
        return !count;
    }

    ~LinkedList() {
        Node* node = start.next;

        while (node != &end) {
            Node* next = node->next;
            delete node;
            node = next;
        }
    }

private:
    Node start{};
    Node end{};
    int count{};
};

class LFUCache {
public:
    LFUCache(int capacity) : cap{ capacity } {}
    
    int get(int key) {
        if (!nodes.contains(key)) return -1;
        increment_freq(nodes[key]);
        return nodes[key]->val;
    }
    
    void put(int key, int value) {
        if (nodes.contains(key)) {
            nodes[key]->val = value;
            increment_freq(nodes[key]);
            return;
        }

        if (nodes.size() == cap) {
            // evict
            LinkedList::Node* front = freq[minf].pop_start();
            nodes.erase(front->key);
            delete front;
        }

        LinkedList::Node* nw = new LinkedList::Node{
            .val = value, .key = key, .freq = 1
        };

        freq[1].push_end(nw);
        nodes[key] = nw;
        minf = 1;
    }

private:
    void increment_freq(LinkedList::Node* node) {
        freq[node->freq].erase(node);
        freq[node->freq + 1].push_end(node);
        if (freq[node->freq].empty() && minf == node->freq) {
            ++minf;
            // freq.erase(node->freq);
        }
        ++(node->freq);
    }

    std::unordered_map<int,
        LinkedList::Node*> nodes; // key -> node
    std::unordered_map<int,
        LinkedList> freq; // freq -> list
    
    int minf{};
    int cap{};
};
