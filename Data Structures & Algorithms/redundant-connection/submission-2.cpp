class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();

        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0] - 1].emplace_back(edge[1] - 1);
            e[edge[1] - 1].emplace_back(edge[0] - 1);

            std::unordered_set<int> vis;
            if (!dfs(0, 0, e, vis)) return edge;
        }

        return { -1, -1 };
    }

private:
    bool dfs(int v, int p, std::vector<std::vector<int>>& e,
        std::unordered_set<int>& vis) {
        if (vis.contains(v)) return false;

        vis.emplace(v);

        for (int to : e[v]) {
            if (to == p) continue;
            if (!dfs(to, v, e, vis)) return false;
        }

        return true;
    }
};
