#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(target + 1));

        for (int i = 1; i <= n; ++i) {
            for (int w = 0; w <= target; ++w) {
                const int val = stones[i - 1];
                dp[i][w] = dp[i - 1][w];

                if (w >= val) {
                    dp[i][w] = std::max(dp[i][w], dp[i - 1][w - val] + val);
                }
            }
        }

        return sum - 2 * dp[n][target];
    }
};