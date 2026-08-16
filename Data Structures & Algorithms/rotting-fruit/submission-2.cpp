class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        std::queue<std::pair<int, int>> q;

        int fruit = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 2) q.push({ x, y });
                else if (grid[y][x] == 1) ++fruit;
            }
        }

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        int steps = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                const auto [x, y] = q.front();
                q.pop();

                for (const auto [dx, dy] : dirs) {
                    const int nx = dx + x;
                    const int ny = dy + y;

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                        grid[ny][nx] != 1) continue;
                    
                    --fruit;
                    grid[ny][nx] = 2;

                    q.push({ nx, ny });
                }
            }
            ++steps;
        }
        return fruit ? -1 : steps - 1;
    }
};
