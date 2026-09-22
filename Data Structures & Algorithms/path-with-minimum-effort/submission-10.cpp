class Solution {
public:
    // TC!!

    // +bs
    // +kruskal
    // SPFA
    int minimumEffortPath(vector<vector<int>>& grid) {
        const int w = grid[0].size();
        const int h = grid.size();
        
        std::queue<std::pair<int, int>> q;
        q.push({ 0, 0 });

        std::vector<bool> enq(w * h);

        std::vector<int> dist(w * h,
            std::numeric_limits<int>::max());
        dist[0] = 0;

        const std::vector<std::pair<int, int>> dirs = {
            { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
        };

        while (!q.empty()) {
            const auto [max, v] = q.front();
            q.pop();

            enq[v] = false;

            const int x = v % w;
            const int y = v / w;

            for (const auto [dx, dy] : dirs) {
                const int nx = dx + x;
                const int ny = dy + y;

                if (nx < 0 || nx >= w ||
                    ny < 0 || ny >= h) continue;
                
                const int nv = ny * w + nx;
                const int new_dist = std::max(dist[v],
                    std::abs(grid[y][x] - grid[ny][nx]));
                if (new_dist < dist[nv]) {
                    dist[nv] = new_dist;
                    if (!enq[nv]) {
                        enq[nv] = true;
                        q.push({ new_dist, nv });
                    }
                }
            }
        }

        return dist.back();
    }
};