class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();

        std::vector<int> dp(n + 1);

        for (int i = n - 2; i >= 0; --i) {
            dp[i] = std::numeric_limits<int>::max();

            for (int j = i + 1; j <
                std::min(n, i + nums[i] + 1); ++j) {
                if (dp[j] == std::numeric_limits<int>::max()) continue;
                
                dp[i] = std::min(dp[i], 1 + dp[j]);
            }
        }

        return dp[0];
    }
};
