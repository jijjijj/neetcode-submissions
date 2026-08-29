class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int w = heights[0].size();
        const int h = heights.size();
        std::vector<std::vector<int>> dist(h,
            std::vector<int>(w, std::numeric_limits<int>::max()));
        
        std::priority_queue<
            std::tuple<int, int, int>,
            std::vector<std::tuple<int, int, int>>,
            std::greater<>> q; // diff, x, y

        q.push({ 0, 0, 0 });
        dist[0][0] = 0;

        const std::vector<std::pair<int, int>> dirs = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };
        
        // std::unordered_set<int> vis;
        // vis.emplace(0);

        while (!q.empty()) {
            const auto [max, x, y] = q.top();
            q.pop();

            // vis.emplace(y * w + x);

            // dist[y][x] = std::min(dist[y][x], max);
            for (const auto& [dx, dy] : dirs) {
                const int cx = dx + x;
                const int cy = dy + y;

                if (cx < 0 || cy < 0 || cx >= w || cy >= h) continue;

                const int d = std::max(max,
                    std::abs(heights[cy][cx] - heights[y][x]));

                if (d < dist[cy][cx]) {
                    dist[cy][cx] = d;
                    q.push({ d, cx, cy });
                }
            }
        }

        return dist.back().back();
    }
};