class MyHashSet {
public:
    MyHashSet() {}
    
    void add(int key) {
        set[key / 32] |= mask(key);
    }
    
    void remove(int key) {
        set[key / 32] &= ~mask(key);
    }
    
    bool contains(int key) {
        return set[key / 32] & mask(key);
    }

private:
    int mask(int key) {
        return 1 << (key % 32);
    }
    int set[100001 / 32 + 1]{};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */