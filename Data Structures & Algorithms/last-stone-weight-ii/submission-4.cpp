#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::unordered_set<int> dp = { 0 };
        
        for (const int n : stones) {
            std::unordered_set<int> new_dp = dp;

            for (const int w : dp) {
                if (w + n == target) return sum - 2 * target;

                if (w + n < target) {
                    new_dp.emplace(w + n);
                }
            }

            dp = std::move(new_dp);
        }

        const int max = *std::max_element(dp.begin(), dp.end());

        return sum - 2 * max;
    }
};