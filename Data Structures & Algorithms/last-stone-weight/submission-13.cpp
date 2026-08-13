#include <ranges>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::sort(stones.begin(), stones.end());

        int n = stones.size();

        while (n > 1) {
            const int diff = stones[n - 1] -
                stones[n - 2];
            n -= 2;

            if (!diff) continue;

            const int index = std::lower_bound(stones.begin(),
                stones.begin() + n, diff) - stones.begin();
            
            stones.emplace_back(0);

            // std::cout << index << " " << n << std::endl;
            // break;
            for (int i = n; i > index; --i)
                stones[i] = stones[i - 1];
                ++n;
            stones[index] = diff;
            // n = std::max(n, index);
        }
        // std::cout << n;
        return n > 0 ? stones.front() : 0;
    }
};
