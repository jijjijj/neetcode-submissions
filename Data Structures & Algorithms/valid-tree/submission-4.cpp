class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        std::vector<std::vector<int>> e(n);
        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        std::unordered_set<int> vis;
        dfs(0, 0, vis, e);

        return vis.size() == n;
    }

private:
    bool dfs(int v, int parent,
        std::unordered_set<int>& vis,
        const std::vector<std::vector<int>>& edges) {
        vis.emplace(v);

        for (int to : edges[v]) {
            if (to == parent) continue;
            if (vis.contains(to)) return false;

            if (!dfs(to, v, vis, edges)) return false;
        }

        return true;
    }
};
