class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<int>> dp(n + 1,
            std::vector<int>(n + 1, 100001));

        for (int i = 1; i <= n; ++i)
            dp[i][i] = 0;

        for (const auto& t : times)
            dp[t[0]][t[1]] = t[2];

        for (int t = 1; t <= n; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dp[i][j] > (dp[i][t] + dp[t][j])) {
                        dp[i][j] = dp[i][t] + dp[t][j];
                    }
                }
            }
        }

        const int max = *std::max_element(dp[k].begin() + 1, dp[k].end());

        return max != 100001 ? max : -1;
    }
};
