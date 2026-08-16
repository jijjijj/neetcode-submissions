class Solution {
public:
    vector<int> findOrder(int n,
        vector<vector<int>>& prerequisites) {
        e.resize(n);
        indeg.resize(n);

        for (const auto& edge : prerequisites) {
            e[edge[1]].emplace_back(edge[0]);
            ++indeg[edge[0]];
        }

        // int total = n;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) dfs(i);
        }
        
        // std::cout << total;
        if (res.size() != n) res.clear();

        return res;
    }

private:
    void dfs(int v) {
        if (vis.contains(v)) return;

        res.emplace_back(v);
        vis.emplace(v);

        for (const int to : e[v]) {
            if (!--indeg[to]) {
                dfs(to);
            }
        }
    }

    std::unordered_set<int> vis;
    std::vector<int> res;
    std::vector<int> indeg;
    std::vector<std::vector<int>> e;
};
