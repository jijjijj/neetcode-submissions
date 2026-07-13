
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::map<std::string, int> map;

        for (const auto& str : strs) {
            std::array<uint16_t, 26> arr = {};

            for (char c : str) ++arr[c - 'a'];

            std::string key;
            key.reserve(26 * 2);
            for (uint16_t x : arr) {
                key += x & 0xff;
                key += x & 0xff00;
            }

            if (const auto it = map.find(key); it != map.end()) {
                result[it->second].emplace_back(str);
            } else {
                map[key] = result.size();
                result.emplace_back(std::vector{ str });
            }
        }

        return result;
    }
};
