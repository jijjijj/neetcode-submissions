class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_map<std::string, std::string> out;

        for (const auto& path : paths) {
            out[path[0]] = path[1];
        }

        std::string start = paths[0][0];

        while (out.contains(start)) {
            start = out[start];
        }

        return start;
    }
};
