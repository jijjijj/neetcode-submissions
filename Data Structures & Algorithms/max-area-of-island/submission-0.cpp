class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == 1) {
                    mx = std::max(mx, bfs(grid, x, y));
                }
            }
        }

        return mx;
    }

private:
    int bfs(std::vector<std::vector<int>>& grid,
        int x, int y) {
        std::queue<std::pair<int, int>> q; // x, y
        q.push(std::pair{ x, y });
        
        int cleared = 0;
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            if (cx >= 0 && cy >= 0 && cx < grid[0].size() &&
                cy < grid.size() && grid[cy][cx] == 1) {
                ++cleared;
                grid[cy][cx] = 0;

                q.push(std::pair{ cx + 1, cy });
                q.push(std::pair{ cx - 1, cy });
                q.push(std::pair{ cx, cy + 1 });
                q.push(std::pair{ cx, cy - 1 });
            }
        }
        return cleared;
    }
};
