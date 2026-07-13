#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();

        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0] - 1].emplace_back(edge[1] - 1);
            e[edge[1] - 1].emplace_back(edge[0] - 1);
        }

        std::unordered_set<int> vis;
        std::unordered_set<int> cycle;
        dfs(0, 0, e, vis, cycle);

        for (const auto& edge : edges | std::views::reverse) {
            if (cycle.contains(edge[0] - 1) &&
                cycle.contains(edge[1] - 1)) {
                return edge;
            }
        }

        return { -1, -1 };
    }

private:
    bool dfs(int v, int p, std::vector<std::vector<int>>& e,
        std::unordered_set<int>& vis,
        std::unordered_set<int>& cycle) {
        if (vis.contains(v)) {
            _start = v;
            return false;
        }

        vis.emplace(v);

        for (int to : e[v]) {
            if (to == p) continue;
            if (!dfs(to, v, e, vis, cycle)) {
                if (_start != -1) cycle.emplace(to);
                if (_start == v) _start = -1;
                return false;
            }
        }

        return true;
    }

    bool _start = -1;
};
