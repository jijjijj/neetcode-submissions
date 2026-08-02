class Solution {
public:
    int numDistinct(string s, string t) {
        const int lens = s.size();
        const int lent = t.size();

        std::vector<std::vector<int>> dp(lent + 1,
            std::vector<int>(lens + 1));

        dp[lent][lens] = 1;

        for (int i = lent; i >= 0; --i) {
            for (int j = lens - 1; j >= 0; --j) {
                dp[i][j] = dp[i][j + 1];
                if (i < lent && t[i] == s[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
                // std::cout << dp[i][j] << " ";
            }
            // std::cout << std::endl;
        }

        return dp[0][0];
    }
};
