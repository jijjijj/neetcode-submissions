#include <bits/stdc++.h>
using namespace std;

class ArrHash {
public:
    size_t operator()(const array<int,26>& a) const {
        // Simple, fast hash for 26 ints
        size_t h = 0;
        for (int i = 0; i < 26; ++i) {
            h = h * 1315423911u + static_cast<size_t>(a[i]);
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: signature -> list of indices
        unordered_map<array<int,26>, vector<int>, ArrHash> mp;

        for (int i = 0; i < (int)strs.size(); ++i) {
            array<int,26> cnt{};
            for (char c : strs[i]) ++cnt[c - 'a'];
            mp[cnt].push_back(i);
        }

        vector<vector<string>> res;
        res.reserve(mp.size());

        for (auto &p : mp) {
            vector<string> group;
            group.reserve(p.second.size());
            for (int idx : p.second) group.push_back(strs[idx]); // copy once per string into result
            res.push_back(std::move(group));
        }
        return res;
    }
};