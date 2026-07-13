class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();

        std::vector<std::vector<int>> vis_p(m,
            std::vector<int>(n, 0));
        std::vector<std::vector<int>> vis_a(m,
            std::vector<int>(n, 0));

        std::queue<std::pair<int, int>> q_pac;
        std::queue<std::pair<int, int>> q_atl;

        for (int y = 0; y < m; ++y) {
            q_pac.push(std::pair{ 0, y });
            q_atl.push(std::pair{ n - 1, y });
        }

        for (int x = 0; x < n; ++x) {
            q_pac.push(std::pair{ x, 0 });
            q_atl.push(std::pair{ x, m - 1 });
        }

        bfs(q_pac, heights, vis_p);
        bfs(q_atl, heights, vis_a);

        vector<vector<int>> res;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (vis_a[y][x] && vis_p[y][x]) {
                    res.emplace_back(std::vector{ y, x });
                }
            }
        }

        return res;
    }

private:
    void bfs(std::queue<std::pair<int, int>>& q,
        vector<vector<int>>& heights,
        vector<vector<int>>& vis) {
        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            vis[y][x] = 1;

            for (const auto& c : coords) {
                const int cx = x + c.first;
                const int cy = y + c.second;

                if (cx >= 0 && cy >= 0 &&
                    cx < heights[0].size() &&
                    cy < heights.size() &&
                    heights[cy][cx] >= heights[y][x] &&
                    !vis[cy][cx]) {
                    q.push(std::pair{ cx, cy });
                }
            }
        }
    }
};
