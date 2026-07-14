class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string,
            std::vector<std::string>> mp;

        for (const auto& str : strs) {
            int freq[26]{};

            for (const char c : str) ++freq[c - 'a'];

            std::string key(26, '0');
            
            for (int i = 0; i < 26; ++i)
                key[i] = static_cast<char>(freq[i]);

            mp[key].emplace_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(mp.size());

        for (auto& [_, vec] : mp) {
            result.emplace_back(std::move(vec));
        }

        return result;
    }
};
