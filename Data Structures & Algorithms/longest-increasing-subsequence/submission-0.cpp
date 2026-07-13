class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size());

        dp[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            int max = 0;
            for (int j = 0; j < i; ++j) {
                if (dp[j] > max && nums[j] < nums[i]) {
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
        }

        return dp.back();
    }
};
