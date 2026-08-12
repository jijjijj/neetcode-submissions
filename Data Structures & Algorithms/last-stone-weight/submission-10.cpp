#include <ranges>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::ranges::sort(stones);

        int n = stones.size() - 1;

        while (n > 1) {
            for (int v : stones) std::cout << v << " ";
            std::cout << std::endl;
            const int diff = stones[n] -
                stones[n - 1];
            n -= 2;

            if (!diff) continue;

            const int index = std::ranges::lower_bound(stones, diff) -
                stones.begin();
            
            stones.emplace_back(0);


            std::cout << index << " " << n << std::endl;
            // break;
            ++n;
            for (int i = n; i > index; --i) stones[i] = stones[i - 1];
            stones[index] = diff;
        }

        return n >= 0 ? stones[0] : 0;
    }
};
