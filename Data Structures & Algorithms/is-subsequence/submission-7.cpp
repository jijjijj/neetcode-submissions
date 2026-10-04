class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int ssize = s.size();
        const int tsize = t.size();

        std::vector<std::vector<bool>> dp(ssize + 1,
            std::vector<bool>(tsize + 1));

        std::fill(dp.back().begin(), dp.back().end(), true);

        for (int i = ssize - 1; i >= 0; --i) {
            for (int j = tsize - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};