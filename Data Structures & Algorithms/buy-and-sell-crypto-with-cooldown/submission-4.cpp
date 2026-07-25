class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        std::vector<std::vector<int>> dp(n + 2,
            std::vector<int>(2));

        for (int i = n - 1; i >= 0; --i) {
            {
                const int buy_today = dp[i + 1][0] - prices[i];
                const int skip_today = dp[i + 1][1];

                dp[i][1] = std::max(buy_today, skip_today);
            }

            {
                const int sell_today = dp[i + 2][1] + prices[i];
                const int skip_today = dp[i + 1][0];

                dp[i][0] = std::max(sell_today, skip_today);
            }
        }

        return dp[0][1];     
    }
};
