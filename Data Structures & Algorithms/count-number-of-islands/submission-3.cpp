class Dsu {
public:
    explicit Dsu(int n) {
        parent.resize(n);
        _size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            _size[i] = 1;
        }
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b) return false;
        if (_size[a] < _size[b]) std::swap(a, b);

        parent[b] = a;
        _size[a] += _size[b];

        return true;
    }

private:
    int find_set(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    std::vector<int> parent;
    std::vector<int> _size;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        Dsu dsu(grid[0].size() * grid.size());

        const auto index = [&grid](int x, int y)
            { return grid[0].size() * y + x; };

        const std::vector<std::pair<int, int>> coords = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int islands = 0;

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == '1') {
                    const int ind = index(x, y);

                    islands++;

                    for (const auto& coord : coords) {
                        const int nx = x + coord.first;
                        const int ny = y + coord.second;

                        if (nx < 0 || ny < 0 || nx >= grid[0].size() ||
                            ny >= grid.size() || grid[ny][nx] != '1') continue;
                        islands -= !!dsu.union_sets(ind, index(nx, ny));
                    }
                }
            }
        }

        return islands;
    }
};
