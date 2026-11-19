class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_set<std::string> out;

        for (const auto& path : paths) {
            out.emplace(path[0]);
        }

        for (const auto& path : paths) {
            if (!out.contains(path[1])) return path[1];
        }

        return "";
    }
};
