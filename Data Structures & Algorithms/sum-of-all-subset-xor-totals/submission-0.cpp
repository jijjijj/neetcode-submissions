#include <ranges>

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        std::vector<int> subsets;
        subsets.emplace_back(0);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = subsets.size() - 1; j >= 0; --j) {
                subsets.emplace_back(subsets[j] ^ nums[i]);
            }
        }

        return std::accumulate(subsets.begin(), subsets.end(), 0);
    }
};