class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        const int cInf = 1'000'000 * 1000 + 1;
        const int n = nums.size();
        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(k + 1, cInf));

        // for (int j = n - 1; j >= 0; --j) dp[j][0] = dp[j + 1][0] + nums[j];

        for (int t = 1; t <= k; ++t) {
            for (int i = n - 1; i >= 0; --i) {
                dp[n][t - 1] = 0;
                int cur = 0;
                for (int j = i; j <= n - t; ++j) {
                    cur += nums[j];
                    dp[i][t] = std::min(dp[i][t],
                        std::max(cur, dp[j + 1][t - 1]));
                }
            }
        }

        return dp[0][k];
    }
};