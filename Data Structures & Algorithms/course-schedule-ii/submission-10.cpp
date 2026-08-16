class Solution {
public:
    vector<int> findOrder(int n,
        vector<vector<int>>& prerequisites) {
        e.resize(n);

        for (const auto& edge : prerequisites) {
            e[edge[0]].emplace_back(edge[1]);
        }

        std::unordered_map<int, bool> vis;

        for (int i = 0; i < n; ++i) {
            if (!vis.contains(i) &&
                dfs(i, vis)) {
                return {};
            }
        }

        return res;
    }

private:
    bool dfs(int i, std::unordered_map<int, bool>& vis) {
        if (vis.contains(i)) return vis[i];

        vis[i] = true;

        for (const int to : e[i]) {
            if (dfs(to, vis))
                return true;
        }

        vis[i] = false;
        res.emplace_back(i);

        return false;
    }

    std::vector<int> res;
    std::vector<std::vector<int>> e;
};
