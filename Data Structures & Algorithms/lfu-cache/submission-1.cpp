class LFUCache {
public:
    LFUCache(int capacity) : _cap{ capacity } {}
    
    int get(int key) {
        if (!mp.contains(key)) return -1;

        increment_freq(key);

        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.size() == _cap) {
            mp.erase(lf.back().key);
            lf.erase(std::prev(lf.end()));
        }

        increment_freq(key);
        mp[key]->val = value;
    }

private:
    void increment_freq(int key) {
        const auto it = mp.contains(key)
            ? mp[key]
            : lf.insert(lf.end(), Val{ key, 0, 0 });

        ++(it->freq);

        auto where = it;
        while (where != lf.begin() &&
            std::prev(where)->freq <= it->freq) {
            --where;
        }

        mp[key] = lf.insert(where, *it);
        lf.erase(it);

        // for (auto [key, freq, _] : lf) {
        //     std::cout << "(" << key << ", " << freq << ") ";
        // }
        // std::cout << std::endl;
    }

    struct Val {
        int key{};
        int freq{};
        int val{};
    };

    std::list<Val> lf;  // key, freq, val
    std::unordered_map<int,
        decltype(lf)::iterator> mp;  // key, it in lf
    int _cap{};
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */