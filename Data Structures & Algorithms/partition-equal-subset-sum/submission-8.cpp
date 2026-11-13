class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) return false;

        const int target = sum >> 1;

        std::vector<std::bitset<100>> dp(target + 1);

        for (int i = 0; i <= target; ++i) {
            if (i && !dp[i].any()) continue;

            for (int j = 0; j < nums.size(); ++j) {
                if (!dp[i][j] && (i + nums[j]) <= target) {
                    dp[i + nums[j]] |= dp[i];
                    dp[i + nums[j]][j] = true;
                    // std::cout << (i + nums[j]) << std::endl;
                }
            }
        }

        return dp[target].any();
    }
};
