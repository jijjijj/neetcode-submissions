class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        int abs_max = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int max = 0;
            for (int j = 0; j < i; ++j) {
                if (dp[j] > max && nums[j] < nums[i]) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;

            abs_max = std::max(abs_max, dp[i]);
        }

        return abs_max;
    }
};
