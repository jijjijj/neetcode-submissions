class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::vector<bool> vis(n, false);

        std::vector<std::vector<int>> e(n);
        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        std::queue<int> q;
        q.push(0);

        int total = n;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            vis[v] = true;
            --total;

            for (int to : e[v]) {
                if (vis[to]) continue;

                q.push(to);
            }
        }

        return total == 0 ? (n - edges.size() == 1) : false;
    }
};
