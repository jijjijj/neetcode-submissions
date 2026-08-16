class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (size[a] > size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    bool same(int a, int b) {
        return find(a) == find(b);
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
    void solve(vector<vector<char>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();
        const int cBorder = w * h;
        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        Dsu dsu{ w * h + 1 };

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] != 'O') continue;

                for (const auto [dx, dy] : dirs) {
                    const int cx = dx + x;
                    const int cy = dy + y;

                    if (cx < 0 || cy < 0 || cx >= w || cy >= h ||
                        grid[cy][cx] != 'O') continue;

                    dsu.union_sets(y * w + x, cy * w + cx);
                }

                if (!x || !y || x == w - 1 || y == h - 1)
                    dsu.union_sets(y * w + x, cBorder);
            }
        }

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!dsu.same(y * w + x, cBorder) &&
                    grid[y][x] == 'O') {
                    grid[y][x] = 'X';
                }
            }
        }
    }
};
