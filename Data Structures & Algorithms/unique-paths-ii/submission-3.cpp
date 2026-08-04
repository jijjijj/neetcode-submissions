class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        std::vector<int> dp(w + 1);
        
        dp[w - 1] = 1;

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                if (!grid[y][x]) {
                    dp[x] += dp[x + 1];
                } else {
                    dp[x] = 0;
                }
            }
        }

        return dp[0];
    }
};