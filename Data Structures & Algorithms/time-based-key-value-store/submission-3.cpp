class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        const auto it = mp[key].upper_bound(timestamp);

        return (it != mp[key].begin()) ? std::prev(it)->second : "";
    }

private:
    std::unordered_map<std::string,
        std::map<int, std::string>> mp; 
};
