class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> dp;

        dp[0] = 1;
        int ans = 0;
        while (dp.size() != 1 || !dp.contains(target)) {
            std::unordered_map<int, int> new_dp;
            new_dp[target] = dp[target];
            for (const int n : nums) {
                for (const auto [sum, ways] : dp) {
                    if (sum + n > target) continue;
                    // std::cout << (sum + n) << " ";
                    const int base = dp.contains(sum + n) ? dp[sum + n] : 0;
                    new_dp[sum + n] += ways;

                    // if (sum + n == target) ans += new_dp[sum + n];
                }
            }

            // std::cout << "\n";

            dp = std::move(new_dp);
        }

        return dp[target];
    }
};