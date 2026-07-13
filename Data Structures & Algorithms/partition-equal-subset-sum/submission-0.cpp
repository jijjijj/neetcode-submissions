class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2) return false;

        std::vector<std::vector<bool>> dp(sum + 1,
            std::vector<bool>(nums.size() + 1));

        dp[0][0] = true;

        for (int j = 1; j <= nums.size(); ++j) {
            for (int i = 1; i <= sum; ++i) {
                dp[i][j] = dp[i][j - 1];
                if (nums[j - 1] <= i) dp[i][j] = dp[i][j] | dp[i - nums[j - 1]][j - 1];

                // if (dp[i][j]) std::cout << i << " ";
                if ((i == sum / 2) && dp[i][j]) return true;
            }
        }

        return false;
    }
};
