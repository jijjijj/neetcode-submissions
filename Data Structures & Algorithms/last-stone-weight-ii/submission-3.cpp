#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::vector<int> dp(target + 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int w = target; w >= 0; --w) {
                if (stones[i] <= w) {
                    dp[w] = std::max(dp[w],
                        dp[w - stones[i]] + stones[i]);
                }
            }
        }

        return sum - 2 * dp[target];
    }
};