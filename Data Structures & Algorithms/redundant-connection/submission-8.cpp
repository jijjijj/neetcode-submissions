#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        std::unordered_map<int, int> indeg;
        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
            ++indeg[edge[0]];
            ++indeg[edge[1]];
        }

        std::queue<int> q;

        for (const auto& [v, in] : indeg) {
            if (in == 1) q.push(v);
        }

        std::unordered_map<int, bool> vis(n);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            vis[v] = true;

            for (int to : e[v]) {
                if (vis[to]) continue;
                if (--indeg[to] == 1) q.push(to);
            }
        }

        for (const auto& edge : edges | std::views::reverse) {
            if (indeg[edge[0]] == 2 && indeg[edge[1]] == 2) {
                return edge;
            }
        }

        return { -1, -1 };
    }
};
