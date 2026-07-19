class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets) {
            e[t[0]].emplace_back(t[1]);
        }

        for (auto& [_, adj] : e) {
            std::ranges::sort(adj, std::greater<>{});
        }

        std::vector<std::string> result;

        dfs("JFK", result);
        std::ranges::reverse(result);
        return result;
    }

private:
    void dfs(const std::string& cur,
        std::vector<std::string>& result) {
        while (!e[cur].empty()) {
            const std::string to = e[cur].back();
            e[cur].pop_back();
            dfs(to, result);
        }

        result.emplace_back(cur);
    }

    std::unordered_map<std::string,
        std::vector<std::string>> e;
};
