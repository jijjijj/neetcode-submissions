class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        std::queue<std::pair<int, int>> q;

        const std::vector<std::pair<int, int>> dirs = {
            { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
        };

        const int h = matrix.size();
        const int w = matrix[0].size();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                bool has_inc = false;

                for (const auto& dir : dirs) {
                    const int nx = x + dir.first;
                    const int ny = y + dir.second;

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

                    if (matrix[ny][nx] < matrix[y][x]) {
                        has_inc = true;
                        break;
                    }
                }

                if (!has_inc) {
                    q.push(std::pair{ x, y });
                    std::cout << x << " " << y << std::endl;
                }
            }
        }

        int dist = 0;
        while (!q.empty() && dist < 50) {
            ++dist;
            
            for (int i = q.size(); i > 0; --i) {
                auto [x, y] = q.front();
                q.pop();

                // std::cout << x << " " << y << std::endl;

                for (const auto& dir : dirs) {
                    const int nx = x + dir.first;
                    const int ny = y + dir.second;

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

                    if (matrix[ny][nx] > matrix[y][x]) {
                        q.push(std::pair{ nx, ny });
                    }
                }

                // matrix[y][x] = -200;
            }

            // std::cout << std::endl;
        }

        return dist;
    }
};
