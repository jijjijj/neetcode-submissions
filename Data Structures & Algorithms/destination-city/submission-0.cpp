class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_map<std::string, int> outdeg;

        for (const auto& path : paths) {
            ++outdeg[path[0]];
        }

        for (const auto& path : paths) {
            if (!outdeg[path[1]]) return path[1];
        }

        return "";
    }
};
