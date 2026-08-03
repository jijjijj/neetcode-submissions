class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        std::vector<std::vector<int>> dp(h + 1,
            std::vector<int>(w + 1));
        
        if (!grid[h - 1][w - 1]) dp[h - 1][w - 1] = 1;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                if (!grid[y][x]) {
                    dp[y][x] += dp[y][x + 1] + dp[y + 1][x];
                }
            }
        }

        return dp[0][0];
    }
};