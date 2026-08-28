#include <ranges>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int n = stones.size();
        const int sum = std::accumulate(stones.begin(), stones.end(), 0);
        const int target = sum / 2;

        std::bitset<3001> bs;
        bs[0] = true;

        for (const int n : stones) {
            bs |= (bs << n);
        }

        int max = 0;
        for (int i = 0; i <= target; ++i) {
            if (bs[i]) max = i;
        }

        return sum - 2 * max;
    }
};