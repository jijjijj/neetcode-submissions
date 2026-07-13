class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int curr = 0;

        for (int i = 1; i < prices.size(); ++i) {
            max = std::max(max, prices[i] - prices[curr]);
            if (prices[i] < prices[curr]) curr = i; 
        }

        return max;
    }
};
