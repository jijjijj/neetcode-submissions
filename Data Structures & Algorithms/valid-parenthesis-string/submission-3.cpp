class Solution {
public:
    bool checkValidString(string s) {
        const int n = s.size();

        std::vector<bool> dp(n + 1, false);
        std::vector<bool> new_dp(n + 1, false);

        dp[0] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (int open = 0; open <= n; ++open) {
                bool res = false;

                if (s[i] == '*') {
                    res |= dp[open + 1];
                    if (open) res |= dp[open - 1];
                    res |= dp[open];
                } else if (s[i] == '(') {
                    res |= dp[open + 1];
                } else if (open > 0) {
                    res |= dp[open - 1];
                }

                new_dp[open] = res;
            }

            std::swap(dp, new_dp);
        }

        return dp[0];
    }
};
