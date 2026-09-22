class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
        // for (int p : parent) std::cout << p << " ";
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

    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
};

class Solution {
public:
    // TC!!

    // +bs
    // kruskal
    // SPFA
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int w = heights[0].size();
        const int h = heights.size();
        
        if (w == 1 && h == 1) return 0;

        Dsu dsu(w * h);

        // diff, compr. from, compr. to
        std::vector<std::tuple<int, int, int>> edges;

        const auto compr = [w, h](int x, int y) { return w * y + x; };

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (x) {
                    const int diff = std::abs(heights[y][x] -
                        heights[y][x - 1]);
                    edges.emplace_back(
                        std::tuple{ diff, compr(x - 1, y), compr(x, y) }
                    );
                }
                if (y) {
                    const int diff = std::abs(heights[y][x] -
                        heights[y - 1][x]);
                    edges.emplace_back(
                        std::tuple{ diff, compr(x, y - 1), compr(x, y) }
                    );
                }
            }
        }

        std::ranges::sort(edges, [](const auto& a, const auto& b) {
            return std::get<0>(a) < std::get<0>(b);
        });

        for (const auto& [_, from, to] : edges) {
            dsu.union_sets(from, to);

            if (dsu.find(0) == dsu.find(w * h - 1)) return _;
        }

        return -1;
    }
};