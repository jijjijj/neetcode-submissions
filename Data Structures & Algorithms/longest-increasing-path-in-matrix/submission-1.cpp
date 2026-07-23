class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        std::queue<std::pair<int, int>> q;

        const std::vector<std::pair<int, int>> dirs = {
            { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
        };

        const int h = matrix.size();
        const int w = matrix[0].size();

        std::unordered_map<int, int> indeg;

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                for (const auto& dir : dirs) {
                    const int nx = x + dir.first;
                    const int ny = y + dir.second;

                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

                    if (matrix[ny][nx] < matrix[y][x]) {
                        ++indeg[y * w + x];
                    }
                }

                if (!indeg[y * w + x]) {
                    q.push(std::pair{ x, y });
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
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
                        if (!--indeg[ny * w + nx]) {
                            q.push(std::pair{ nx, ny });
                        }
                    }
                }
            }
        }

        return dist;
    }
};
