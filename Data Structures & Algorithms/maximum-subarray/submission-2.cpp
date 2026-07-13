class Solution {
public:
    // dp, dp space-optimized, divide&conquer
    int maxSubArray(vector<int>& nums) {
        std::vector<std::vector<int>> dp(2,
            std::vector<int>(nums.size()));

        dp[1].back() = nums.back();
        dp[0].back() = nums.back();

        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[1][i] = std::max(nums[i], nums[i] + dp[1][i + 1]);
            dp[0][i] = std::max(dp[1][i], dp[0][i + 1]);
        }

        return dp[0][0];
    }
};
