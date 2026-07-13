class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();

        std::vector<std::vector<int>> vis(m,
            std::vector<int>(n, 0));

        std::queue<std::pair<int, int>> q_pac;
        std::queue<std::pair<int, int>> q_atl;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if ((x > 0 && x + 1 < n) &&
                    (y > 0 && y + 1 < m)) continue;

                if (!x || !y) q_pac.push(std::pair{ x, y });
                if (x == n - 1 || y == m - 1) q_atl.push(std::pair{ x, y });
            }
        }

        bfs(q_pac, heights, vis, 0b01);
        bfs(q_atl, heights, vis, 0b10);

        vector<vector<int>> res;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (vis[y][x] == 0b11) {
                    res.emplace_back(std::vector{ y, x });
                }
            }
        }

        return res;
    }

private:
    void bfs(std::queue<std::pair<int, int>>& q,
        vector<vector<int>>& heights,
        vector<vector<int>>& vis, int fill) {
        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            vis[y][x] |= fill;

            for (const auto& c : coords) {
                const int cx = x + c.first;
                const int cy = y + c.second;

                if (cx >= 0 && cy >= 0 &&
                    cx < heights[0].size() &&
                    cy < heights.size() &&
                    heights[cy][cx] >= heights[y][x] &&
                    !(vis[cy][cx] & fill)) {
                    q.push(std::pair{ cx, cy });
                }
            }
        }
    }
};
