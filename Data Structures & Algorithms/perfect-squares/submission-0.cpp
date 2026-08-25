class Solution {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1,
            std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int x = 1; x * x <= i; ++x) {
                if (i < x * x) break;

                dp[i] = std::min(dp[i], dp[i - x * x] + 1);
            }
        }

        return dp[n];
    }
};