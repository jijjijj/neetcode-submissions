class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::ranges::sort(coins);
        std::vector<std::vector<int>> dp(coins.size(),
            std::vector<int>(amount + 1));

        for (int j = 0; j < coins.size(); ++j) {
            dp[j][0] = 1;

            const int c = coins[j];
            for (int i = 1; i <= amount; ++i) {
                    if (j) dp[j][i] = dp[j - 1][i];

                if (c <= i) {
                    dp[j][i] += dp[j][i - c];
                }

                // std::cout << dp[j][i] << " ";
            }
            // std::cout << std::endl;
        }

        return dp[coins.size() - 1][amount];
    }
};
