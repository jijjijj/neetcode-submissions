class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        const int cInf = 99999;

        std::vector<std::vector<int>> dp(h + 1,
            std::vector<int>(w + 1, cInf));
        
        dp[h - 1][w] = 0;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                dp[y][x] = std::min(dp[y][x + 1],
                    dp[y + 1][x]) + grid[y][x];
            }
        }

        return dp[0][0];
    }
};