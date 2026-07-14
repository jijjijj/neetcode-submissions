class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string,
            std::vector<std::string>> mp;

        for (const auto& str : strs) {
            std::string copy = str;
            std::ranges::sort(copy);

            mp[copy].emplace_back(str);
        }

        std::vector<std::vector<std::string>> result;

        for (auto& [_, vec] : mp) {
            result.emplace_back(std::move(vec));
        }

        return result;
    }
};
