class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int max = std::numeric_limits<int>::max();
        std::vector<int> dp(amount + 1, max);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != max) dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == max ? -1 : dp[amount];
    }
};
