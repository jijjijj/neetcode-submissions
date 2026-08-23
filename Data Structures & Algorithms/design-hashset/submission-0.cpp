class MyHashSet {
public:
    MyHashSet() : buckets(1000) {
        
    }
    
    void add(int key) {
        if (contains(key)) return;
        
        const int k = key % buckets.size();

        buckets[k].emplace_back(key);
    }
    
    void remove(int key) {
        const int k = key % buckets.size();
        
        for (auto it = buckets[k].begin();
            it != buckets[k].end(); ++it) {
            if (*it == key) {
                buckets[k].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        const int k = key % buckets.size();
        
        for (const int k_ : buckets[k]) {
            if (k_ == key) return true;
        }

        return false;
    }

private:
    std::vector<std::list<int>> buckets;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */