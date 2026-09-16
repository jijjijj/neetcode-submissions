class Solution {
public:
    vector<vector<int>> buildMatrix(int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions) {
        std::vector<int> row =
            order(k, rowConditions);
        std::vector<int> col =
            order(k, colConditions);

        if (row.empty() || col.empty()) return {};

        std::vector<std::vector<int>> grid(k,
            std::vector<int>(k));
        std::vector<int> rowy(k + 1);
        for (int y = 0; y < row.size(); ++y)
            rowy[row[y]] = y;
        for (int x = 0; x < col.size(); ++x) {
            grid[rowy[col[x]]][x] = col[x];
        }

        return grid;
    }

private:
    std::vector<int> order(int k,
        const vector<vector<int>>& edges) {
        std::vector<std::vector<int>> e(k + 1);

        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];

            e[a].emplace_back(b);
        }

        std::vector<int> res;
        res.reserve(k);

        vis.clear();

        for (int i = 1; i <= k; ++i) {
            if (!dfs(i, e, res)) return {};
        }

        std::ranges::reverse(res);

        return res;
    }

    bool dfs(int v,
        std::vector<std::vector<int>>& e,
        std::vector<int>& res) {
        if (vis.contains(v)) return vis[v];
        
        vis[v] = false;

        for (const int to : e[v]) {
            if (!dfs(to, e, res)) {
                return false;
            }
        }

        vis[v] = true;
        res.emplace_back(v);

        return true;
    }

    std::unordered_map<int, bool> vis;
};