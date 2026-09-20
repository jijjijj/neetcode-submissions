#include <ranges>

class Solution {
public:
    // +backtracking
    // +recursion
    // bitmask
    // bits
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (int s = 0; s < (1 << nums.size()); ++s) {
            int total = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if ((1 << i) & s) {
                    total ^= nums[i];
                }
            }

            res += total;
        }
        return res;
    }
};