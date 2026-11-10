class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size());
        int max = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            dp[i] = 1;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
            max = std::max(max, dp[i]);
        }

        return max;
    }
};
