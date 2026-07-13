
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::map<std::array<int, 26>, int> map;

        for (const auto& str : strs) {
            std::array<int, 26> arr = {};

            for (char c : str) ++arr[c - 'a'];

            if (const auto it = map.find(arr); it != map.end()) {
                result[it->second].emplace_back(str);
            } else {
                map[arr] = result.size();
                result.emplace_back(std::vector<std::string>{ str });
            }
        }

        return result;
    }
};
