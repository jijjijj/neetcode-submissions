class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        e.resize(n);

        for (const auto& edge : prerequisites) {
            e[edge[1]].emplace_back(edge[0]);
        }

        std::unordered_map<int, bool> vis;

        for (int i = 0; i < n; ++i) {
            if (!vis.contains(i) && dfs(i, vis)) return false;
        }

        return true;
    }

private:
    bool dfs(int i, std::unordered_map<int, bool>& vis) {
        if (vis.contains(i)) return vis[i];

        vis[i] = true;

        bool ret = false;
        for (const int to : e[i]) {
            if (dfs(to, vis)) {
                ret = true;
                break;
            }
        }

        vis[i] = false;

        return ret;
    }

    std::vector<std::vector<int>> e;
};
