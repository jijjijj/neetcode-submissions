class Solution {
public:
    vector<vector<int>> buildMatrix(int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions) {
        std::unordered_map<int, int> row =
            order(k, rowConditions);
        std::unordered_map<int, int> col =
            order(k, colConditions);

        if (row.empty() || col.empty()) return {};

        std::vector<std::vector<int>> grid(k,
            std::vector<int>(k));

        for (const auto [val, x] : col) {
            grid[row[val]][x] = val;
        }

        return grid;
    }

private:
    std::unordered_map<int, int> order(int k,
        const vector<vector<int>>& edges) {
        std::vector<int> indeg(k + 1);
        std::vector<std::vector<int>> e(k + 1);

        for (const auto& edge : edges) {
            const int a = edge[0];
            const int b = edge[1];

            e[a].emplace_back(b);

            ++indeg[b];
        }

        std::queue<int> q;

        for (int i = 1; i <= k; ++i) {
            if (!indeg[i]) q.push(i);
        }

        std::unordered_map<int, int> res;
        
        while (!q.empty()) {
            const int v = q.front();
            q.pop();
            --k;
            // 2 above 1 above 3
            res[v] = res.size();

            for (const int to : e[v]) {
                if (!--indeg[to]) {
                    q.push(to);
                }
            }
        }

        if (k) return {};

        return res;
    }
};