#include <ranges>

class Solution {
public:
    // backtracking
    // recursion
    // bitmask
    // bits
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(const vector<int>& nums, int curr, int i) {
        if (i == nums.size()) return curr;

        return dfs(nums, curr ^ nums[i], i + 1) +
            dfs(nums, curr, i + 1);
    }
};