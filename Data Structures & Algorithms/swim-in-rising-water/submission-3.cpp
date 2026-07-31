class Solution {
public:
    // bs + dfs
    // djikstra
    // + kruskal's
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        std::vector<std::vector<std::tuple<int, int, int>>> e(n);

        int l = std::numeric_limits<int>::max();
        int r = std::numeric_limits<int>::min();

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                l = std::min(grid[y][x], l);
                r = std::max(grid[y][x], r);
            }
        }

        while (l <= r) {
            const int mid = l + (r - l) / 2;

            std::unordered_set<int> vis;
            if (dfs(mid, grid, vis, 0, 0)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool dfs(int t,
        const std::vector<std::vector<int>>& grid,
        std::unordered_set<int>& vis, int x, int y) {
        const int n = grid.size();
        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        if (vis.contains(y * n + x)) return false;
        if (y == n - 1 && x == n - 1) return true;

        vis.emplace(y * n + x);

        for (const auto [dx, dy] : dirs) {
            const int nx = dx + x;
            const int ny = dy + y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            
            if (grid[ny][nx] <= t) {
                if (dfs(t, grid, vis, nx, ny)) return true;
            }
        }

        return false;
    }
};
