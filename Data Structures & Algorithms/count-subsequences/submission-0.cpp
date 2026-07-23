class Solution {
public:
    int numDistinct(string s, string t) {
        const int lens = s.size();
        const int lent = t.size();

        std::vector<std::vector<int>> dp(lens + 1,
            std::vector<int>(lent + 1));

        dp[0][0] = 1;

        for (int j = 0; j <= lent; ++j) {
            for (int i = 0; i <= lens; ++i) {
                if (!i && !j) continue;

                if (i && j && s[i - 1] == t[j - 1]) dp[i][j] = dp[i][j - 1];
                if (i) dp[i][j] += dp[i - 1][j];

                // std::cout << dp[i][j] << " ";
            }
            // std::cout << std::endl;
        }

        return dp[lens][lent];
    }
};
