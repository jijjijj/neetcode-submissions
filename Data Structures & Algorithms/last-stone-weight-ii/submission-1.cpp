#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::vector<std::vector<int>> dp(target + 1,
            std::vector<int>(n + 1));

        for (int w = 0; w <= target; ++w) {
            for (int i = n - 1; i >= 0; --i) {
                dp[w][i] = dp[w][i + 1];

                if (stones[i] <= w) {
                    dp[w][i] = std::max(dp[w][i],
                        dp[w - stones[i]][i + 1] + stones[i]);
                }
            }
        }

        return sum - 2 * dp[target][0];
    }
};