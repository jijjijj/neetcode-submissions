#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);

            std::unordered_set<int> vis;
            if (dfs(edge[0], -1, e, vis)) {
                return edge;
            }
        }

        return { -1, -1 };
    }

private:
    bool dfs(int v, int parent,
        const std::vector<std::vector<int>>& e,
        std::unordered_set<int>& vis) {
        if (vis.contains(v)) return true;

        vis.emplace(v);

        for (int to : e[v]) {
            if (parent == to) continue;
            if (dfs(to, v, e, vis)) return true;
        }

        return false;
    }
};
