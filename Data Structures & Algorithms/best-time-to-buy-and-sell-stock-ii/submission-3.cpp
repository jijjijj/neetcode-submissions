class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        
        int dp_1_buy = 0;
        int dp_1_sell = 0;
        int dp_2_buy = 0;
        int dp_2_sell = 0;

        for (int i = n - 1; i >= 0; --i) {
            {
                // max profit starting from day i, with no stock being held
                const int t = std::max(dp_2_buy, dp_2_sell - prices[i]);

                dp[i][0] = std::max(dp[i + 1][0], dp[i + 1][1] - prices[i]);
            }
            {

            }
        }

        return dp[0][0];
    }
};