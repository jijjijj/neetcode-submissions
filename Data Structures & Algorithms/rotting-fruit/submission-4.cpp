class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        int fruit = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                fruit += (grid[y][x] == 1);
            }
        }

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        int steps = 0;
        int colored = 1;
        while (fruit && colored) {
            colored = 0;
            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    if (grid[y][x] != 2) continue;

                    for (const auto [dx, dy] : dirs) {
                        const int nx = dx + x;
                        const int ny = dy + y;

                        if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                            grid[ny][nx] != 1) continue;
                        
                        ++colored;
                        --fruit;
                        grid[ny][nx] = 3;
                    }
                }
            }

            for (int y = 0; y < h; ++y) {
                for (int x = 0; x < w; ++x) {
                    if (grid[y][x] == 3) grid[y][x] = 2;
                }
            }
            ++steps;
        }
        return fruit ? -1 : steps;
    }
};
