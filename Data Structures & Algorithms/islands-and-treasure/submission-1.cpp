class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int, int>> q; // x, y
        
        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (!grid[y][x]) {
                    q.push(std::pair{ x, y });
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto [nx, ny] = q.front();
                q.pop();

                if (ny < 0 || nx < 0 || nx >= grid[0].size() ||
                    ny >= grid.size() || grid[ny][nx] < dist) continue;

                grid[ny][nx] = dist;

                q.push(std::pair{ nx + 1, ny });
                q.push(std::pair{ nx - 1, ny });
                q.push(std::pair{ nx, ny + 1 });
                q.push(std::pair{ nx, ny - 1 });
            }

            ++dist;
        }
    }

private:
    constexpr static int kINF = std::numeric_limits<int32_t>::max();
};
