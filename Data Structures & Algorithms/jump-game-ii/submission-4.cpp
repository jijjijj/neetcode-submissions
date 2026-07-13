class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        
        std::vector<int> dp(n,
            1000000);
        dp[n - 1] = 0;
        
        for (int i = n - 2; i >= 0; --i) {
            const int to = std::min(n - 1, i + nums[i]);
            for (int j = i; j <= to; ++j) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }

        return dp[0];
    }
};
