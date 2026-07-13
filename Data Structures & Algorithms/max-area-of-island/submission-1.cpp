class Dsu {
public:
    Dsu(int n) : parent(n), _size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (_size[a] < _size[b]) std::swap(a, b);
        parent[b] = a;
        _size[a] += _size[b];

        return true;
    }

    int size(int v) {
        return _size[find(v)];
    }

private:
    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }

    std::vector<int> parent;
    std::vector<int> _size;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        Dsu dsu(grid.size() * grid[0].size());

        int mx = 0;

        const auto index = [&grid](int x, int y)
            { return y * grid[0].size() + x; };
        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == 1) {
                    const int ind = index(x, y);

                    for (const auto& c : coords) {
                        const int cx = x + c.first;
                        const int cy = y + c.second;
                        
                        if (cx >= 0 && cy >= 0 && cx < grid[0].size() &&
                            cy < grid.size() && grid[cy][cx] == 1) {
                            dsu.union_sets(ind, index(cx, cy));
                        }
                    }

                    mx = std::max(mx, dsu.size(ind));
                }
            }
        }

        return mx;
    }
};
