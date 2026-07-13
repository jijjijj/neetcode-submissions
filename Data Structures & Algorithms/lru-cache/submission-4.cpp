class LRUCache {
public:
    LRUCache(int capacity)
        : _capacity{capacity} {}
    
    int get(int key) {
        if (auto it = _hash.find(key); it != _hash.end()) {
            _order.erase(it->second.second);
            _order.emplace_back(key);
            it->second.second = --_order.end();
            return it->second.first;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (auto it = _hash.find(key); it != _hash.end()) {
            _order.erase(it->second.second);
            _hash.erase(it);
        }
        
        if (_hash.size() == _capacity) {
            const int to_rem = _order.front();
            _order.pop_front();
            _hash.erase(to_rem);
        }

        _order.emplace_back(key);
        _hash[key] = std::pair{ value, --_order.end() };
    }

private:
    int _capacity{};
    std::list<int> _order;
    std::unordered_map<int,
        std::pair<int, decltype(_order)::iterator>> _hash;
};
