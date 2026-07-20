class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(std::pair{ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = mp[key].size() - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            if (mp[key][mid].first <= timestamp) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (r < 0 || r >= mp[key].size()) return "";

        return mp[key][r].second;
    }

private:
    std::unordered_map<std::string,
        std::vector<std::pair<int, std::string>>> mp; 
};
