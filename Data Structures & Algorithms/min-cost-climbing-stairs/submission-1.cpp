class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        
        int dp_2 = 0;
        int dp_1 = 0;

        for (int i = 2; i <= n; ++i) {
            const int tmp = std::min(dp_1 + cost[i - 1],
                dp_2 + cost[i - 2]);
            dp_2 = dp_1;
            dp_1 = tmp;
        }

        return dp_1;
    }
};
