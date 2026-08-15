class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1), n{n} {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (size[a] < size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        --n;

        return true;
    }

    int count() {
        return n;
    }

private:
    int find(int v) {
        if (parent[v] == v) return v;

        return v = find(parent[v]);
    }

    std::vector<int> size;
    std::vector<int> parent;
    int n{};
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const std::vector<std::pair<int, int>> dirs = {
            { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
        };

        const int h = grid.size();
        const int w = grid[0].size();

        Dsu dsu{ w * h };

        int count = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == '1') {
                    for (auto [dx, dy] : dirs) {
                        const int nx = x + dx;
                        const int ny = y + dy;

                        if (nx < 0 || ny < 0 || nx >= w ||
                            ny >= h || grid[ny][nx] != '1') continue;
                        
                        dsu.union_sets(ny * w + nx, x + y * w);
                    }
                } else {
                    ++count;
                }
            }
        }
        return dsu.count() - count;
    }
};
