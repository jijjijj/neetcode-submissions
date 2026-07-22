class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m,
            std::vector<int>(n));

        dp[0][0] = 1;

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (x > 0) dp[y][x] += dp[y][x - 1];
                if (y > 0) dp[y][x] += dp[y - 1][x];
            }
        }

        return dp[m - 1][n - 1];
    }
};
