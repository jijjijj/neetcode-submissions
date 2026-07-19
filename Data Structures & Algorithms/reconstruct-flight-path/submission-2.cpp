class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        _tickets = tickets.size();
        for (int i = 0; i < tickets.size(); ++i) {
            e[tickets[i][0]].emplace(std::pair{ tickets[i][1], i });
        }

        std::vector<std::string> result;

        dfs("JFK", result, 0);

        return result;
    }

private:
    bool dfs(const std::string& cur,
        std::vector<std::string>& result,
        int used) {
        result.emplace_back(cur);

        if (used == _tickets) return true;

        for (const auto& [to, t] : e[cur]) {
            if (vis.contains(t)) continue;

            vis.emplace(t);
            if (dfs(to, result, used + 1)) return true;
            vis.erase(t);
        }

        result.pop_back();

        return false;
    }

    std::unordered_set<int> vis;
    std::unordered_map<std::string,
        std::set<std::pair<std::string, int>>> e;
    int _tickets{};
};
