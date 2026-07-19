class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string, std::set<std::string>> e;

        for (const auto& t : tickets) {
            e[t[0]].emplace(t[1]);
        }

        std::vector<std::string> result;

        dfs("JFK", e, result);

        return result;
    }

private:
    void dfs(const std::string& cur,
        std::unordered_map<std::string, std::set<std::string>>& e,
        std::vector<std::string>& result) {
        result.emplace_back(cur);

        auto it = e[cur].begin();
        if (it != e[cur].end()) {
            auto to = *it;
            e[cur].erase(it);
            dfs(to, e, result);
            return;
        }
    }
};
