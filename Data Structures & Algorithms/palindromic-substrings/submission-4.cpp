class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();

        int sum = 0;

        std::vector<std::vector<bool>> dp(n,
            std::vector<bool>(n));

        for (int l = 1; l <= n; ++l) {
            for (int i = n - l; i >= 0; --i) {
                const bool pal = dp[i][i + l - 1] =
                    s[i] == s[i + l - 1] &&
                    (l <= 2 || dp[i + 1][i + l - 2]);
                sum += pal;
            }
        }

        return sum;
    }
};
