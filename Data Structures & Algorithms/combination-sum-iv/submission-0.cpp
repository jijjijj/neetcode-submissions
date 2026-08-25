class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> dp;

        dp[0] = 1;

        while (true) {
            std::unordered_map<int, int> new_dp;

            bool repeat = false;
            for (const int n : nums) {
                for (const auto [sum, ways] : dp) {
                    new_dp[sum + n] = dp[sum + n] + ways;

                    if (sum + n < target) repeat = true;
                }
            }

            dp = std::move(new_dp);

            if (!repeat) break;
        }

        return dp[target];
    }
};