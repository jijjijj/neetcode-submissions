class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        const int cInf = 1'000'000 * 1000 + 1;
        const int n = nums.size();
        std::vector<int> dp(n + 1, cInf);
        std::vector<int> dp2(n + 1, cInf);
        dp2[n] = 0;

        for (int t = 1; t <= k; ++t) {
            for (int i = n - 1; i >= 0; --i) {
                dp[i] = cInf;
                int cur = 0;
                for (int j = i; j <= n - t; ++j) {
                    cur += nums[j];
                    dp[i] = std::min(dp[i],
                        std::max(cur, dp2[j + 1]));
                }
            }
            dp2 = dp;
        }

        return dp.front();
    }
};