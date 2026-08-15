class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        int max = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x]) {
                    int count = 1;

                    std::queue<std::pair<int, int>> q;
                    q.push({ x, y });
                    grid[y][x] = 0;

                    while (!q.empty()) {
                        const auto [cx, cy] = q.front();
                        q.pop();

                        for (const auto [dx, dy] : dirs) {
                            const int nx = dx + cx;
                            const int ny = dy + cy;

                            if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                                !grid[ny][nx]) continue;
                            
                            ++count;
                            grid[ny][nx] = 0;

                            q.push({ nx, ny });
                        }
                    }

                    max = std::max(max, count);
                }
            }
        }
        return max;
    }
};
