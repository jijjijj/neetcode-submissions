class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        std::queue<std::pair<int, int>> q;

        const auto add = [&grid, &q, w](int x, int y) {
            if (grid[y][x] == 'O') {
                q.push({ x, y });
            }
        };

        for (int x = 0; x < w; ++x) {
            add(x, 0);
            add(x, h - 1);
        }

        for (int y = 0; y < h; ++y) {
            add(0, y);
            add(w - 1, y);
        }

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        while (!q.empty()) {
            const auto [x, y] = q.front();
            q.pop();

            if (grid[y][x] != 'O') continue;
            grid[y][x] = 'T';

            for (const auto [dx, dy] : dirs) {
                const int cx = dx + x;
                const int cy = dy + y;

                if (cx < 0 || cy < 0 || cx >= w || cy >= h ||
                    grid[cy][cx] != 'O') continue;

                q.push({ cx, cy });
            }
        }

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 'O') {
                    grid[y][x] = 'X';
                } else if (grid[y][x] == 'T') {
                    grid[y][x] = 'O';
                }
            }
        }
    }
};
