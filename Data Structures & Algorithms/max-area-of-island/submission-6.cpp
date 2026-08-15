class Dsu {
public:
    explicit Dsu(int n) : parent(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return size[a];
        if (size[a] > size[b]) std::swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return size[a];
    }

    int size_(int v) {
        return size[v];
    }

private:
    int find(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find(parent[v]);
    }
    
    std::vector<int> size;
    std::vector<int> parent;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        Dsu dsu{ w * h };

        int max = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x]) {
                    // max = std::max(1, max);
                    // grid[y][]
                    for (const auto [dx, dy] : dirs) {
                        const int nx = dx + x;
                        const int ny = dy + y;

                        if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                            !grid[ny][nx]) continue;
                        
                        // grid[ny][nx] = 0;
                        dsu.union_sets(
                            ny * w + nx, y * w + x);
                    }

                    max = std::max(max,
                        dsu.size_(y * w + x));
                }
            }
        }
        return max;
    }
};
