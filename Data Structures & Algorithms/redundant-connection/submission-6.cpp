#include <ranges>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();

        std::vector<std::vector<int>> e(n);
        std::vector<int> indegree(n);

        for (const auto& edge : edges) {
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            e[v].emplace_back(u);
            e[u].emplace_back(v);

            ++indegree[v];
            ++indegree[u];
        }

        std::queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            --indegree[v];

            for (int to : e[v]) {
                if (--indegree[to] == 1) {
                    q.push(to);
                }
            }
        }

        for (const auto& edge : edges | std::views::reverse) {
            if (indegree[edge[0] - 1] > 1 && indegree[edge[1] - 1] > 1) {
                return edge;
            }
        }

        return { -1, -1 };
    }
};
