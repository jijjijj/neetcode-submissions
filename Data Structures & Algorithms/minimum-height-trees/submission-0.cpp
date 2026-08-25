class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {        
        std::vector<int> min(n);

        std::vector<std::vector<int>> e(n);
        std::unordered_map<int, int> indeg;

        for (int i = 0; i < n; ++i) indeg[i];
        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
            ++indeg[edge[1]];
            ++indeg[edge[0]];
        }

        std::queue<std::tuple<int, int, int>> q; // v, dist, parent
        for (auto& [v, in] : indeg) {
            if (in == 1) {
                q.push({ v, 1 , -1 });
            }
        }

        while (!q.empty()) {
            const auto [v, d, p] = q.front();
            q.pop();

            min[v] = std::max(min[v], d);

            for (const int to : e[v]) {
                if (to == p) continue;

                q.push({ to, d + 1, v });
            }
        }

        const int mn = *std::min_element(min.begin(), min.end());

        std::vector<int> res;
        for (int i = 0; i < n; ++i)
            if (min[i] == mn) res.emplace_back(i);

        return res;
    }
};