#include <ranges>

class Solution {
public:
    // backtracking
    // +recursion
    // bitmask
    // bits
    int subsetXORSum(vector<int>& nums) {
        std::vector<int> curr;
        dfs(nums, curr, 0);
        return res;
    }

private:
    void dfs(const vector<int>& nums, std::vector<int>& curr, int i) {
        int total = 0;
        for (const int v : curr) total ^= v;
        res += total;

        for (int j = i; j < nums.size(); ++j) {
            curr.emplace_back(nums[j]);
            dfs(nums, curr, j + 1);
            curr.pop_back();
        }
    }

    int res = 0;
};