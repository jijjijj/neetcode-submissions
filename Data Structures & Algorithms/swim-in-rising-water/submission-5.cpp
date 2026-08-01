class Solution {
public:
    // + bs + dfs
    // djikstra
    // + kruskal's
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        std::priority_queue<std::tuple<int, int, int>,
            std::vector<std::tuple<int, int, int>>,
            std::greater<>> q;
        q.push(std::tuple{ grid[0][0], 0, 0 });

        std::vector<bool> vis(n * n);

        while (!q.empty()) {
            const auto [t, x, y] = q.top();
            q.pop();

            if (vis[y * n + x]) continue;
            vis[y * n + x] = true;
            if (x == n - 1 && y == n - 1) return t;

            for (const auto [dx, dy] : dirs) {
                const int nx = x + dx;
                const int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                // if (grid[ny][nx] > t) continue;

                q.push(std::tuple{ std::max(grid[ny][nx], t), nx, ny });
            }
        }

        return -1;
    }
};
