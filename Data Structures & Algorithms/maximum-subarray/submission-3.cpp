class Solution {
public:
    // dp, dp space-optimized, divide&conquer
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
        }

        return dp.back();
    }
};
