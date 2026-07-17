class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] = std::max(mp[s[i]], i);
        }

        std::vector<int> result;
        std::unordered_set<char> acc;
        
        int size = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];
            ++size;
            
            end = std::max(end, mp[c]);

            if (i == end) {
                result.emplace_back(size);
                size = 0;
            }
        }

        return result;
    }
};
