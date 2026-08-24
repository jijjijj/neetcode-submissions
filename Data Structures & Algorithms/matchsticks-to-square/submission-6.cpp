#include <ranges>

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        const int n = nums.size();
        
        std::ranges::sort(nums | std::views::reverse);

        const int total = std::accumulate(
            nums.begin(), nums.end(), 0);

        if (total % 4) return false;
        dp.resize(1 << n, cNegInf);

        return dfs(total / 4, nums, (1 << n) - 1) == 0;
    }

private:
    int dfs(int total, std::vector<int>& nums, int mask) {
        if (!mask) return 0;
        if (dp[mask] != cNegInf) return dp[mask];

        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) {
                const int res = dfs(total, nums, mask ^ (1 << i));
                if (res >= 0 && res + nums[i] <= total) {
                    dp[mask] = (res + nums[i]) % total;
                    return dp[mask];
                }

                if (mask == (1 << nums.size()) - 1) break;
            }
        }

        dp[mask] = -1;
        return dp[mask];
    }

    const int cNegInf = std::numeric_limits<int>::min();
    std::vector<int> dp;
};