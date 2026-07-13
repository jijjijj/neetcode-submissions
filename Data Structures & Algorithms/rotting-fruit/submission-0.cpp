class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fruits = 0;
        
        std::queue<std::pair<int, int>> q; // x, y

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == 1) ++fruits;
                if (grid[y][x] == 2) q.push(std::pair{ x, y });
            }
        }

        int time = -1;

        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto [nx, ny] = q.front();
                q.pop();

                for (const auto& c : coords) {
                    const int cx = nx + c.first;
                    const int cy = ny + c.second;

                    if (cx < 0 || cy < 0 || cx >= grid[0].size() ||
                        cy >= grid.size() || grid[cy][cx] != 1) continue;
                    
                    grid[cy][cx] = 2;
                    --fruits;

                    q.push(std::pair{ cx, cy });
                }
            }

            ++time;
        }

        return fruits ? -1 : time;
    }
};
