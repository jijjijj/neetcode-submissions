class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int n = coins.size();
        std::ranges::sort(coins);
        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(amount + 1));

        for (int j = n - 1; j >= 0; --j) {
            dp[j][0] = 1;

            const int c = coins[j];
            for (int i = 1; i <= amount; ++i) {
                dp[j][i] = dp[j + 1][i];

                if (c <= i) {
                    dp[j][i] += dp[j][i - c];
                }
            }
        }

        return dp[0][amount];
    }
};
