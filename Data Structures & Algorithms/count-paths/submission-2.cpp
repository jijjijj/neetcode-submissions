class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n);
        dp[0] = 1;

        for (int y = 0; y < m; ++y) {
            for (int x = 1; x < n; ++x) {
                dp[x] += dp[x - 1];
            }
        }

        return dp.back();
    }
};
