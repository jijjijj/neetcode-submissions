class LRUCache {
public:
    LRUCache(int capacity) : cap{ capacity } {}
    
    int get(int key) {
        if (const auto it = latest.find(key);
            it != latest.end()) {
            return it->second->second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (const auto it = latest.find(key);
            it != latest.end()) {
            values.erase(it->second);
        }

        values.emplace_back(std::pair{ key, value });
        latest[key] = --(values.end());

        if (values.size() > cap) {
            latest.erase(values.front().first);
            values.erase(values.begin());
        }
    }

private:
    std::list<std::pair<int, int>> values;
    std::unordered_map<int, decltype(values)::iterator> latest;
    int cap{};
};
