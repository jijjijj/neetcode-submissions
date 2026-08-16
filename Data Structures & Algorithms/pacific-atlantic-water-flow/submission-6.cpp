class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        std::queue<std::tuple<int, int, int>> q;
        
        const int h = grid.size();
        const int w = grid[0].size();

        for (int x = 0; x < w; ++x) {
            q.push({ x, 0, 0 });
            q.push({ x, h - 1, 1 });
        }

        for (int y = 0; y < h; ++y) {
            q.push({ 0, y, 0 });
            q.push({ w - 1, y, 1 });
        }

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        std::vector<
            std::unordered_set<int>> vis(2);

        while (!q.empty()) {
            auto [x, y, n] = q.front();
            q.pop();

            vis[n].emplace(y * w + x);

            for (const auto [dx, dy] : dirs) {
                const int nx = x + dx;
                const int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                    vis[n].contains(ny * w + nx) ||
                    grid[ny][nx] < grid[y][x]) continue;
                
                vis[n].emplace(ny * w + nx);

                q.push({ nx, ny, n });
            }
        }

        std::vector<std::vector<int>> res;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (vis[0].contains(y * w + x) &&
                    vis[1].contains(y * w + x)) {
                    res.emplace_back(std::vector<int>{ y, x });
                }
            }
        }

        return res;
    }
};
