#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::vector<int> dp(target + 1);

        for (int i = n - 1; i >= 0; --i) {
            std::vector<int> new_dp(target + 1);

            for (int w = 0; w <= target; ++w) {

                new_dp[w] = dp[w];

                if (stones[i] <= w) {
                    new_dp[w] = std::max(new_dp[w],
                        dp[w - stones[i]] + stones[i]);
                }
            }

            dp = std::move(new_dp);
        }

        return sum - 2 * dp[target];
    }
};