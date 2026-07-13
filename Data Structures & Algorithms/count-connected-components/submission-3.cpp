class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        std::vector<bool> vis(n);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;

            ++count;

            std::queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                vis[v] = true;

                for (int to : e[v]) {
                    if (vis[to]) continue;
                    q.push(to);
                }
            }
        }

        return count;
    }
};
