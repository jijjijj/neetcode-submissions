class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(n + 1));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= (n / 2 + 1); ++m) {
                int total = 0;
                dp[i][m] = std::numeric_limits<int>::min();
                for (int x = 1; x <= m * 2; ++x) {
                    if (i + x > n) continue;

                    total += piles[i + x - 1];

                    dp[i][m] = std::max(dp[i][m],
                        total - dp[i + x][std::max(x, m)]);
                }
            }
        }

        return (std::accumulate(piles.begin(),
            piles.end(), 0) + dp[0][1]) / 2;
    }
};