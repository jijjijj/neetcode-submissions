class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (size[a] < size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }

private:
    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

    std::vector<int> parent;
    std::vector<int> size;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
        vector<vector<int>>& edges) {
        std::vector<std::unordered_map<int, std::pair<int, int>>> e(n);

        for (int i = 0; i < edges.size(); ++i) {
            auto& edge = edges[i];
            std::swap(edge[0], edge[2]);
            std::swap(edge[1], edge[2]);
            e[edge[1]][edge[2]] = { edge[0], i };
            e[edge[2]][edge[1]] = { edge[0], i };
            edge.emplace_back(i);
        }

        std::ranges::sort(edges);

        Dsu dsu(n);

        std::vector<std::vector<int>> mst_e(n);
        std::vector<std::tuple<int, int, int, int>> mst;
        for (const auto& edge : edges) {
            const int w = edge[0];
            const int a = edge[1];
            const int b = edge[2];
            const int i = edge[3];
            if (dsu.union_sets(a, b)) {
                mst.emplace_back(std::tuple{ a, b, i, w });
                mst_e[a].emplace_back(b);
                mst_e[b].emplace_back(a);
            }
        }

        std::unordered_set<int> critical;
        std::unordered_set<int> pseudo;

        for (const auto [a, b, i, w] : mst) {
            std::unordered_set<int> vis;
            dfs(a, b, mst_e, vis);

            bool crit = true;

            for (int v : vis) {
                for (auto [v2, p] : e[v]) {
                    auto [w2, i2] = p;
                    if (w == w2 && !vis.contains(v2) && (v != a || v2 != b)) {
                        crit = false;
                        pseudo.emplace(i2);
                    }
                }
            }

            if (!crit) {
                pseudo.emplace(i);
            } else {
                critical.emplace(i);
            }
        }

        return { std::vector<int>(critical.begin(), critical.end()),
            std::vector<int>(pseudo.begin(), pseudo.end()) };
    }

private:
    void dfs(int v, int parent,
        const std::vector<std::vector<int>>& mst,
        std::unordered_set<int>& vis) {
        vis.emplace(v);

        for (const auto to : mst[v]) {
            if (parent == to) continue;
            if (vis.contains(to)) continue;

            dfs(to, parent, mst, vis);
        }
    }
};