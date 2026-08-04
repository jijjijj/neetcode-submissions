class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(2));

        for (int i = n - 1; i >= 0; --i) {
            {
                // max profit starting from day i, with no stock being held
                dp[i][0] = std::max(dp[i + 1][0], dp[i + 1][1] - prices[i]);
            }
            {
                // max profit starting from day i, with a stock being held
                dp[i][1] = std::max(dp[i + 1][1], dp[i + 1][0] + prices[i]);
            }
        }

        return dp[0][0];
    }
};