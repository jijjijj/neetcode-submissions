class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        // dp[i][j] - the max profit on the ith day
        // if you're holding the stocks from jth day
        std::vector<std::vector<int>> dp(n,
            std::vector<int>(2));

        int max = 0;
        for (int i = 1; i < n; ++i) {
            const int profit = std::max(0,
                prices[i] - prices[i - 1]);
            dp[i][0] = std::max(dp[i - 1][1], i > 1 ? (dp[i - 2][0] + std::max(0, prices[i] - prices[i - 2])) : 0);
            dp[i][1] = std::max(dp[i - 1][0] + profit, dp[i - 1][1]);
        }

        return std::max(dp.back()[0], dp.back()[1]);
    }
};
