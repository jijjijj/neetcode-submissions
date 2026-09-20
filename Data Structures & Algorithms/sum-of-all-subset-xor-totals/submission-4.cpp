#include <ranges>

class Solution {
public:
    // +backtracking
    // +recursion
    // +bitmask
    // bits
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (const int val : nums) res |= val;
        return res * (1 << (nums.size() - 1));
    }
};