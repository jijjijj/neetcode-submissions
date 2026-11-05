class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (!mp.contains(val)) {
            mp[val] = vals.size();
            vals.emplace_back(val);
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if (mp.contains(val)) {
            mp[vals.back()] = mp[val];
            std::swap(vals[mp[val]], vals.back());
            vals.resize(vals.size() - 1);
            mp.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }

private:
    std::vector<int> vals;
    std::unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */