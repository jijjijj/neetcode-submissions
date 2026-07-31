class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        std::unordered_map<char,
            std::unordered_set<char>> e(27);

        for (const auto& w : words) {
            for (const char& c : w) e[c];
        }

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                const int max = std::min(
                    words[i].size(), words[j].size());
                for (int k = 0; k < max; ++k) {
                    const char a = words[i][k];
                    const char b = words[j][k];
                    if (a != b) {                        
                        e[a].emplace(b);
                        break;
                    } else if (k == max - 1 &&
                        words[i].size() > words[j].size()) {
                        return "";
                    }
                }
            }
        }

        std::unordered_map<char, bool> vis;
        std::string res;

        for (const auto [c, _] : e) {
            if (dfs(res, e, c, vis)) {
                return "";
            }
        }

        std::ranges::reverse(res);
        return res;
    }

private:
    bool dfs(std::string& res, 
        std::unordered_map<char,
            std::unordered_set<char>>& e,char c,
        std::unordered_map<char, bool>& vis) {
        if (vis.contains(c)) {
            return vis[c];
        }

        vis[c] = true;
        for (const char to : e[c]) {
            if (dfs(res, e, to, vis)) {
                return true;
            }
        }
        vis[c] = false;
        res.push_back(c);

        return false;
    }
};
