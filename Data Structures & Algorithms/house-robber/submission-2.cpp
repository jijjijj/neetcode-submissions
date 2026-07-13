class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1];
            if (i > 1) dp[i] = std::max(dp[i], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};
