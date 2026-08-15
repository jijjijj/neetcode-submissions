class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const std::vector<std::pair<int, int>> dirs = {
            { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
        };

        const int h = grid.size();
        const int w = grid[0].size();

        int count = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == '1') {
                    ++count;

                    std::queue<std::pair<int, int>> q;
                    q.push({ x, y });

                    grid[y][x] = '0';

                    while (!q.empty()) {
                        const auto [cx, cy] = q.front();
                        q.pop();

                        for (auto [dx, dy] : dirs) {
                            const int nx = cx + dx;
                            const int ny = cy + dy;

                            if (nx < 0 || ny < 0 || nx >= w ||
                                ny >= h || grid[ny][nx] != '1') continue;
                            
                            grid[ny][nx] = '0';
                            q.push({ nx, ny });
                        }
                    }
                }
            }
        }
        return count;
    }
};
