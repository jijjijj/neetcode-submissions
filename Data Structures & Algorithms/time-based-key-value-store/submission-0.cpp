class TimeMap {
    struct Val {
        std::string val;
        int ts{};
    };
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        _data[key].emplace_back(Val{
            .val = std::move(value), .ts = timestamp });
    }
    
    string get(string key, int timestamp) {
        if (const auto it = _data.find(key); it != _data.end()) {
            const std::vector<Val>& arr = it->second;
            int l = 0;
            int r = arr.size() - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;

                if (arr[mid].ts <= timestamp) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (r < 0 || r >= arr.size()) return "";

            return arr[r].val;
        }

        return "";
    }

private:
    std::unordered_map<std::string,
        std::vector<Val>> _data;
};
