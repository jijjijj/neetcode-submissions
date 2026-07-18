class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.size();
        std::vector<std::vector<bool>> dp(n + 1,
            std::vector<bool>(n + 1, false));

        dp[n][0] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (int open = 0; open <= n; ++open) {
                bool res = false;

                if (s[i] == '*') {
                    res |= dp[i + 1][open + 1];
                    if (open) res |= dp[i + 1][open - 1];
                    res |= dp[i + 1][open];
                } else if (s[i] == '(') {
                    res |= dp[i + 1][open + 1];
                } else if (open > 0) {
                    res |= dp[i + 1][open - 1];
                }

                dp[i][open] = res;
            }
        }

        return dp[0][0];
    }
};
