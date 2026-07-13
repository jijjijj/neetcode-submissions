class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int number = 0;

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == '1') {
                    ++number;
                    fill(grid, x, y);
                }
            }
        }

        return number;
    }

private:
    void fill(vector<vector<char>>& grid, int x, int y) {
        std::queue<std::pair<int, int>> q; // x, y
        q.push(std::pair{ x, y });

        while (!q.empty()) {
            const auto [x1, y1] = q.front();
            q.pop();

            if (x1 < 0 || y1 < 0 || x1 >= grid[0].size() ||
                y1 >= grid.size() || grid[y1][x1] == '0') continue;

            grid[y1][x1] = '0';

            q.push(std::pair{ x1 + 1, y1 });
            q.push(std::pair{ x1 - 1, y1 });
            q.push(std::pair{ x1, y1 + 1 });
            q.push(std::pair{ x1, y1 - 1 });
        }
    }
};
