#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;
        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        std::unordered_set<int> cycle;
        std::unordered_set<int> vis;

        dfs(1, -1, cycle, e, vis);

        for (const auto& edge : edges | std::views::reverse) {
            if (cycle.contains(edge[0]) && cycle.contains(edge[1])) {
                return edge;
            }
        }

        return { -1, -1 };
    }

private:
    bool dfs(int v, int parent,
        std::unordered_set<int>& cycle,
        const std::vector<std::vector<int>>& e,
        std::unordered_set<int>& vis) {
        if (vis.contains(v)) {
            start = v;
            return true;
        }

        vis.emplace(v);

        for (int to : e[v]) {
            if (parent == to) continue;
            if (dfs(to, v, cycle, e, vis)) {
                if (start != -1) cycle.emplace(v);
                if (start == v) start = -1;
                return true;
            }
        }

        return false;
    }

    int start = -1;
};
