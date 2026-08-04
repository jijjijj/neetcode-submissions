class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        
        int dp_1_buy = 0;
        int dp_1_sell = 0;

        for (int i = n - 1; i >= 0; --i) {
            {
                // max profit starting from day i, with no stock being held
                const int new_buy = std::max(dp_1_buy, dp_1_sell - prices[i]);
                const int new_sell = std::max(dp_1_sell, dp_1_buy + prices[i]);

                dp_1_buy = new_buy;
                dp_1_sell = new_sell;

                // std::cout << dp_1_buy<< " " << dp_1_sell << std::endl;
            }
        }

        return dp_1_buy;
    }
};