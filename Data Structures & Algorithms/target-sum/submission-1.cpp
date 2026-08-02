class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();

        std::vector<std::unordered_map<int, int>> dp(n + 1);
        
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (auto& p : dp[i]) {
                const int num = nums[i];
                dp[i + 1][p.first - num] += p.second;
                dp[i + 1][p.first + num] += p.second;
            }
        }

        return dp[n][target];
    }
};
