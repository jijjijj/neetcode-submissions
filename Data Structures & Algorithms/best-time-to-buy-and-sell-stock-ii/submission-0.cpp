class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int j = 0;
        for (int i = 0; i < prices.size(); ++i) {
            profit += std::max(0, prices[i] - prices[j]);
            j = i;
        }

        return profit;
    }
};