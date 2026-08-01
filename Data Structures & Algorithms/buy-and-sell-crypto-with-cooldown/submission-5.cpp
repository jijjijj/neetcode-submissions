class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int dp_buy1 = 0;
        int dp_sell1 = 0;
        int dp_buy2 = 0;

        for (int i = n - 1; i >= 0; --i) {
            int new_dp_buy1 = 0;
            {
                const int buy_today = dp_sell1 - prices[i];
                const int skip_today = dp_buy1;

                new_dp_buy1 = std::max(buy_today, skip_today);
            }

            {
                const int sell_today = dp_buy2 + prices[i];
                const int skip_today = dp_sell1;

                dp_sell1 = std::max(sell_today, skip_today);
            }

            dp_buy2 = dp_buy1;
            dp_buy1 = new_dp_buy1;
        }

        return dp_buy1;
    }
};
