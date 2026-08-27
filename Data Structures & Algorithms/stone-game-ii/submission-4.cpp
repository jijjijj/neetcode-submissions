class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();

        std::vector<int> postfix(n + 1);
        for (int i = n - 1; i >= 0; --i)
            postfix[i] = piles[i] + postfix[i + 1];

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(n + 1));

        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= (n / 2 + 1); ++m) {
                for (int x = 1; x <= m * 2; ++x) {
                    if (i + x > n) continue;

                    dp[i][m] = std::max(dp[i][m],
                        postfix[i] - dp[i + x][std::max(x, m)]);
                }
            }
        }

        return dp[0][1];
    }
};