class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        const int max = sum * 2 + 1;
        const int n = nums.size();

        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(max + 1));
        
        dp[0][sum] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= max; ++j) {
                const int num = nums[i - 1];
                dp[i][j] =
                    (j >= num ? dp[i - 1][j - num] : 0) +
                    (j + num <= max ? dp[i - 1][j + num] : 0);
                // std::cout << dp[i][j] << " ";
            }
            // std::cout << std::endl;
        }

        return dp[n][target + sum];
    }
};
