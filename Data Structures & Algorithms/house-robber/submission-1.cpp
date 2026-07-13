class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        dp[0] = nums[0];

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
};
