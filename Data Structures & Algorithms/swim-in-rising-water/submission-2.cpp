class Dsu {
public:
    explicit Dsu(int n) : _parent(n), _size(n, 1) {
        for (int i = 0; i < n; ++i) _parent[i] = i;
    }

    bool are_same(int a, int b) {
        a = find(a);
        b = find(b);
        
        return a == b;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _size[b];

        return true;
    }

private:
    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

    std::vector<int> _parent;
    std::vector<int> _size;
};

class Solution {
public:
    // bs + dfs
    // djikstra
    // kruskal's
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        std::vector<std::tuple<int, int, int>> e;
        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                e.emplace_back(
                    std::tuple{ grid[y][x], x, y });
            }
        }

        std::ranges::sort(e);

        Dsu dsu(n * n);

        for (const auto [t, x, y] : e) {
            for (const auto [dx, dy] : dirs) {
                const int nx = x + dx;
                const int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (grid[ny][nx] <= t) {
                    dsu.union_sets(ny * n + nx, y * n + x);
                }
            }

            if (dsu.are_same(0, n * n - 1))
                return t;
        }

        return -1;
    }
};
