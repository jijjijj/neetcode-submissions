class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = std::max({ dp[i], j * dp[i - j], (i < n ? i : 0) });
            }
                // std::cout << dp[i] << " ";

        }

        return dp.back();
    }
};