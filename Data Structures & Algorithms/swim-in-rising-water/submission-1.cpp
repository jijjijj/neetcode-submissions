class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();

        std::vector<std::vector<std::pair<int, int>>> e(n * n);
        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                for (const auto& dir : dirs) {
                    const int nx = x + dir.first;
                    const int ny = y + dir.second;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    
                    e[y * n + x].emplace_back(
                        std::pair{ ny * n + nx,
                        std::max(grid[y][x], grid[ny][nx]) });
                }
            }
        }

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> q;
        q.push(std::pair{ 0, 0});

        std::vector<bool> vis(n * n);
        std::vector<int> dist(n * n,
            std::numeric_limits<int>::max());

        while (!q.empty()) {
            const auto [cost, v] = q.top();
            q.pop();

            if (vis[v]) continue;

            vis[v] = true;

            for (const auto& [to, w] : e[v]) {
                if (vis[to]) continue;

                dist[to] = std::min(dist[to], std::max(w, cost));

                q.push(std::pair{ dist[to], to });
            }
        }

        return dist.back();
    }
};
