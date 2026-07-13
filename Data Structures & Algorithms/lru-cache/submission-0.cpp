class LRUCache {
public:
    LRUCache(int capacity)
        : _capacity{ capacity } {}
    
    int get(int key) {
        update_history(key);

        if (const auto it = _data.find(key); it != _data.end()) {
            return it->second;
        }

        return -1;
    }
    
    void put(int key, int value) {
        update_history(key);

        _data[key];

        if (_data.size() > _capacity) {
            const int key = _history.back();
            // std::cout << "evicting " << key << std::endl;
            _history.pop_back();
            _h.erase(key);
            _data.erase(key);
        }

        update_history(key);

        _data[key] = value;
    }

private:
    void update_history(int key) {
        if (auto it = _h.find(key); it != _h.end()) {
            _history.erase(it->second);
        }

        _h[key] = _history.insert(_history.begin(), key);
    }

    std::list<int> _history;
    std::unordered_map<int, std::list<int>::iterator> _h;

    std::unordered_map<int, int> _data;

    int _capacity{};
};
