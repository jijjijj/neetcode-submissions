class MyHashMap {
public:
    MyHashMap() : buckets(1000) {}
    
    void put(int key, int value) {
        const int k = key % buckets.size();

        for (auto& [kk, val] : buckets[k]) {
            if (kk == key) {
                val = value;
                return;
            }
        }

        buckets[k].emplace_back(
            std::pair{ key, value });
    }
    
    int get(int key) {
        const int k = key % buckets.size();
        
        if (buckets[k].empty()) return -1;

        for (const auto [kk, val] : buckets[k]) {
            if (kk == key) return val;
        }

        return -1;
    }
    
    void remove(int key) {
        const int k = key % buckets.size();
        
        for (int i = 0; i < buckets[k].size(); ++i) {
            if (buckets[k][i].first == key) {
                std::swap(buckets[k][i], buckets[k].back());
                buckets[k].pop_back();
                return;
            }
        }
    }

private:
    std::vector<std::vector<std::pair<int, int>>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */