#include <ranges>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums,
        int target) {
        std::vector<int> res{ -1, -1 };

        auto it = std::ranges::lower_bound(
            nums.begin(), nums.end(), target);

        if (it == nums.end() || *it != target) return res;

        auto it2 = std::ranges::upper_bound(
            nums.begin(), nums.end(), target + 1);

        res[0] = (it - nums.begin());
        res[1] = (it2 - nums.begin() - 1);

        return res;
    }
};