class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        std::ranges::sort(nums);

        std::unordered_map<int, int> dp;

        dp[0] = 1;
        
        while (dp.size() != 1 || !dp.contains(target)) {
            std::unordered_map<int, int> new_dp;
            new_dp[target] = dp[target];

            for (const int n : nums) {
                for (const auto [sum, ways] : dp) {
                    if (sum + n > target) continue;
                    
                    new_dp[sum + n] += ways;
                }
            }

            dp = std::move(new_dp);
        }

        return dp[target];
    }
};