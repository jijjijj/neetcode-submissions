class Solution {
public:
    // TC!!

    // bs
    // kruskal
    // SPFA
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int w = heights[0].size();
        const int h = heights.size();
        
        vis.resize(w * h);

        int l = std::numeric_limits<int>::max();
        int r = std::numeric_limits<int>::min();

        for (const auto& row : heights) {
            for (const auto& val : row) {
                l = std::min(l, val);
                r = std::max(r, val);
            }
        }

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            std::fill(vis.begin(), vis.end(), false);

            if (canReach(0, 0, heights, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool canReach(int x, int y,
        const vector<vector<int>>& grid,
        int limit) {
        const int w = grid[0].size();
        const int h = grid.size();

        vis[y * w + x] = true;
        if (x == w - 1 && y == h - 1) return true;
        
        for (const auto [dx, dy] : dirs) {
            const int nx = dx + x;
            const int ny = dy + y;

            if (nx < 0 || ny < 0 ||
                nx >= w || ny >= h ||
                vis[ny * w + nx] ||
                std::abs(grid[y][x] - grid[ny][nx]) > limit) continue;

            if (canReach(nx, ny, grid, limit)) return true;
        }

        return false;
    }

    const std::vector<std::pair<int, int>> dirs = {
        { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } 
    };
    std::vector<bool> vis;
};