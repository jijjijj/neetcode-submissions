class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        const int cInf = 99999;

        std::vector<int> dp(w + 1, cInf);
        
        dp[w] = 0;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                dp[x] = std::min(dp[x + 1],
                    dp[x]) + grid[y][x];
            }
            dp[w] = cInf;
        }

        return dp[0];
    }
};