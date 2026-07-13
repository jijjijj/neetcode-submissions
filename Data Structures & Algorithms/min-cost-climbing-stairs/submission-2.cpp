class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp_1 = 0;
        int dp_2 = 0;

        for (int i = 2; i <= cost.size(); ++i) {
            const int tmp = std::min(
                dp_1 + cost[i - 1], dp_2 + cost[i - 2]);
            dp_2 = dp_1;
            dp_1 = tmp;
        }

        return dp_1;
    }
};
