class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 0; i <= amount; ++i) {
            for (const int c : coins) {
                if (c > i) continue;

                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
