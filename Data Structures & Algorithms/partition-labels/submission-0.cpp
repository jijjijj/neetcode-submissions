class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] = std::max(mp[s[i]], i);
        }

        std::vector<int> result;
        std::unordered_set<char> acc;

        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            acc.emplace(c);

            if (mp[c] == i) {
                // last pos
                acc.erase(c);
            }

            if (acc.empty()) {
                result.emplace_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
