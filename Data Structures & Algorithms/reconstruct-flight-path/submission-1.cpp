class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        _tickets = tickets.size();
        for (const auto& t : tickets) {
            e[t[0]].emplace(t[1]);
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

        for (const auto& to : e[cur]) {
            if (vis[cur].contains(to)) continue;

            vis[cur].emplace(to);
            if (dfs(to, result, used + 1)) return true;
            vis[cur].erase(to);
        }

        result.pop_back();

        return false;
    }

    std::unordered_map<std::string,
        std::unordered_set<std::string>> vis;
    std::unordered_map<std::string,
        std::set<std::string>> e;
    int _tickets{};
};
