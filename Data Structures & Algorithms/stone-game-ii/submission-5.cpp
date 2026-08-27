class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();

        std::vector<std::vector<std::vector<int>>> dp(n + 1,
            std::vector<std::vector<int>>(n + 1, std::vector<int>(2)));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= (n / 2 + 1); ++m) {
                int sum = 0;
                dp[i][m][1] = std::numeric_limits<int>::max();
                for (int x = 1; x <= std::min(m * 2, n - i); ++x) {
                    // 0 - alice, 1 - bob
                    sum += piles[i + x - 1];

                    dp[i][m][0] = std::max(dp[i][m][0],
                        sum + dp[i + x][std::max(x, m)][1]);
                    dp[i][m][1] = std::min(dp[i][m][1],
                        dp[i + x][std::max(x, m)][0]);
                }
            }
        }

        return dp[0][1][0];
    }
};