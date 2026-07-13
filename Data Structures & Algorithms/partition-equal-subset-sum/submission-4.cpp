class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        std::vector<bool> dp(sum + 1);

        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }

        return dp[sum >> 1];
    }
};
