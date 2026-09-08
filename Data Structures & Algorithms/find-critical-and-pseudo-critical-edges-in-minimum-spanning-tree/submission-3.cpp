class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1), count(n) {
        std::ranges::iota(parent, 0);
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (size[a] < size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        --count;

        return true;
    }

    int cnt() {
        return count;
    }

private:
    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

    std::vector<int> parent;
    std::vector<int> size;
    int count{};
};

class Solution {
public:
    // +kruskal
    // +dijkstra
    // kruskal+dfs
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
        vector<vector<int>>& edges) {
        std::vector<std::vector<int>> e;
        for (int i = 0; i < edges.size(); ++i) {
            const auto& edge = edges[i];

            e.emplace_back(std::vector<int>{
                edge[2], edge[0], edge[1], i                
            });
        }

        std::sort(e.begin(), e.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            });
        
        Dsu dsu(n);
        std::unordered_set<int> mst;
        for (int i = 0; i < e.size(); ++i) {
            const auto& edge = e[i];
            if (dsu.union_sets(edge[1], edge[2])) {
                mst.emplace(edge[3]);
                mste[edge[1]].emplace_back(std::tuple{
                    edge[2], edge[0], edge[3]
                });
                mste[edge[2]].emplace_back(std::tuple{
                    edge[1], edge[0], edge[3]
                });
            }
        }

        std::vector<int> critical;

        for (int i = 0; i < e.size(); ++i) {
            const auto& edge = e[i];
            if (mst.contains(edge[3])) continue;
            
            const int size = pseudo.size();
            dfs(edge[1], edge[2], -1, edge[0]);
            if (size != pseudo.size()) {
                pseudo.emplace(edge[3]);
            }
        }

        for (const int i : mst) {
            if (!pseudo.contains(i)) {
                critical.emplace_back(i);
            }
        }

        return { critical, std::vector<int>{
            pseudo.begin(), pseudo.end() } };
    }

private:
    bool dfs(int v, int u, int p, int w) {
        if (v == u) return true;

        for (const auto [to, tow, i] : mste[v]) {
            if (to == p) continue;
            if (dfs(to, u, v, w)) {
                if (tow == w) pseudo.emplace(i);
                return true;
            }
        }
        
        return false;
    }

    std::unordered_map<int,
        std::vector<std::tuple<int, int, int>>> mste;
    std::unordered_set<int> pseudo;
};