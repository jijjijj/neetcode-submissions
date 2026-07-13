class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> e(n);

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        int connected = 0;
        std::vector<bool> vis(n, false);

        for (int s = 0; s < n; ++s) {
            if (vis[s]) continue;

            ++connected;
            
            std::queue<int> q;
            q.push(s);

            while (!q.empty()) {
                const int v = q.front();
                q.pop();

                vis[v] = true;

                for (const int to : e[v]) {
                    if (vis[to]) continue;

                    q.push(to);
                }
            }
        }

        return connected;
    }
};
