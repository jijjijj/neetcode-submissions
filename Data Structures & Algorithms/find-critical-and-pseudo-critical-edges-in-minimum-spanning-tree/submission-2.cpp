// class Dsu {
// public:
//     explicit Dsu(int n) : parent(n, 0), size(n, 1), count(n) {
//         std::ranges::iota(parent, 0);
//     }

//     bool union_sets(int a, int b) {
//         a = find(a);
//         b = find(b);

//         if (a == b) return false;
//         if (size[a] < size[b]) std::swap(a, b);

//         parent[b] = a;
//         size[a] += size[b];
//         --count;

//         return true;
//     }

//     int cnt() {
//         return count;
//     }

// private:
//     int find(int v) {
//         if (v == parent[v]) return v;

//         return parent[v] = find(parent[v]);
//     }

//     std::vector<int> parent;
//     std::vector<int> size;
//     int count{};
// };

class Solution {
public:
    // +kruskal
    // dijkstra
    // kruskal+dfs
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
        vector<vector<int>>& edges) {
        std::vector<std::vector<std::pair<int, int>>> e(n);
        for (int i = 0; i < edges.size(); ++i) {
            const auto& edge = edges[i];

            e[edge[0]].emplace_back(std::pair{
                edge[1], edge[2]
            });
            e[edge[1]].emplace_back(std::pair{
                edge[0], edge[2]
            });
        }

        // std::ranges::sort(e);
        std::vector<int> critical;
        std::vector<int> pseudo;

        // const int ref = mst(n, e, -1, false);
        for (int i = 0; i < edges.size(); ++i) {
            const int w = mst(n, e, edges[i][0], edges[i][1]);

            if (w == edges[i][2]) {
                pseudo.emplace_back(i);
            } else if (w >= edges[i][2]) {
                critical.emplace_back(i);
            }
        }

        return { critical, pseudo };
    }

private:
    int mst(int n,
        const std::vector<std::vector<std::pair<int, int>>>& edges,
        int s, int u) {
        std::vector<int> dist(n, std::numeric_limits<int>::max());

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> q;
        dist[s] = 0;
        q.push({ 0, s });

        while (!q.empty()) {
            auto [w, v] = q.top();
            q.pop();

            // if (dist[v] < w) continue;

            for (const auto& [to, tow] : edges[v]) {
                if ((v == s && to == u) ||
                    (v == u && to == s)) continue;
                if (std::max(tow, w) < dist[to]) {
                    dist[to] = std::max(w, tow);
                    q.push({ dist[to], to });
                }
            }
        }

        return dist[u];
    }
};