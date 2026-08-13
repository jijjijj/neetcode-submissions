#include <ranges>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::sort(stones.rbegin(), stones.rend());

        int n = 0;

        while (n < stones.size() - 1) {
            for (int v : stones) std::cout << v << " ";
            std::cout << std::endl;
            const int diff = stones[n] -
                stones[n + 1];
            n += 2;

            if (!diff) continue;

            const int index = std::lower_bound(stones.begin() + n,
                stones.end(), diff, std::greater<>{}) - stones.begin();
            
            stones.emplace_back(0);

            // std::cout << index << " " << n << std::endl;
            // break;
            for (int i = stones.size() - 1; i > index; --i)
                stones[i] = stones[i - 1];
            stones[index] = diff;
            // n = std::max(n, index);
        }
        // std::cout << n;
        return n < stones.size() ? stones.back() : 0;
    }
};
