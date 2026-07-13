class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::vector<std::vector<int>> vis(heights.size(),
            std::vector<int>(heights[0].size(), 0));
        vector<vector<int>> res;

        for (int y = 0; y < heights.size(); ++y) {
            for (int x = 0; x < heights[0].size(); ++x) {
                if (!vis[y][x]) {
                    dfs(vis, heights, res, x, y);
                }
            }
        }

        return res;
    }

private:
    int dfs(std::vector<std::vector<int>>& vis,
        std::vector<std::vector<int>>& h,
        vector<vector<int>>& result, int x, int y) {
        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        int reach{};

        if (!x || !y) reach |= 1;
        if (x == h[0].size() - 1 ||
            y == h.size() - 1) reach |= 2;

        vis[y][x] = 4;

        for (const auto& c : coords) {
            const int cx = x + c.first;
            const int cy = y + c.second;
            if (cx < 0 || cy < 0 || cx >= h[0].size() ||
                cy >= h.size() || h[cy][cx] > h[y][x]) continue;
            if (vis[cy][cx]) {
                reach |= vis[cy][cx];
                continue;
            }

            reach |= dfs(vis, h, result, cx, cy);
        }

        vis[y][x] = reach;

        if ((vis[y][x] & 1) && (vis[y][x] & 2)) {
            result.emplace_back(std::vector<int>{ y, x });
        }

        return vis[y][x];
    }
};
