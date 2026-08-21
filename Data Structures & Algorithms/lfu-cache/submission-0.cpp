class LFUCache {
public:
    LFUCache(int capacity) : _cap{ capacity } {}
    
    int get(int key) {
        if (!mp.contains(key)) return -1;

        increment_freq(key);

        return std::get<2>(*(mp[key]));
    }
    
    void put(int key, int value) {
        increment_freq(key);
        std::get<2>(*mp[key]) = value;

        if (mp.size() > _cap) {
            mp.erase(std::get<0>(lf.back()));
            lf.erase(--lf.end());
        }
    }

private:
    void increment_freq(int key) {
        const auto it = mp.contains(key)
            ? mp[key]
            : lf.insert(lf.end(), std::tuple{ key, 0, 0 });
        if (!mp.contains(key)) mp[key] = it;

        ++(std::get<1>(*it));

        auto where = it;
        while (std::get<1>(*where) <= std::get<1>(*it) &&
            where != lf.begin()) {
            --where;
        }

        mp[key] = lf.insert(where, *it);
        lf.erase(it);
    }

    std::list<std::tuple<int, int, int>> lf;  // key, freq, val
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