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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
        vector<vector<int>>& edges) {
        std::vector<std::vector<int>> e;
        for (int i = 0; i < edges.size(); ++i) {
            const auto& edge = edges[i];

            e.emplace_back(std::vector<int>{
                edge[2], edge[0], edge[1], i
            });
        }

        std::ranges::sort(e);
        std::vector<int> critical;
        std::vector<int> pseudo;
        
        const int ref = mst(n, e, -1, false);
        for (int i = 0; i < e.size(); ++i) {
            // const auto& edge = edges[i];
            if (mst(n, e, i, false) > ref) {
                critical.emplace_back(e[i][3]);
            } else if (mst(n, e, i, true) == ref) {
                pseudo.emplace_back(e[i][3]);
            }
        }

        return { critical, pseudo };
    }

private:
    int mst(int n, vector<vector<int>>& edges, int e, bool force) {
        Dsu dsu(n);
        int weight = 0;
        if (force) {
            dsu.union_sets(edges[e][1], edges[e][2]);
            weight = edges[e][0];
        }

        for (int i = 0; i < edges.size(); ++i) {
            if (i == e) continue;

            const auto& edge = edges[i];
            if (dsu.union_sets(edge[1], edge[2])) {
                weight += edge[0];
            }
        }

        return dsu.cnt() == 1 ? weight : std::numeric_limits<int>::max();
    }
};