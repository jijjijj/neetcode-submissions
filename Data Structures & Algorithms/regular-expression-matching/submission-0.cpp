class Solution {
public:
    bool isMatch(string s, string p) {
        const int lenp = p.size();
        const int lens = s.size();

        std::vector<std::vector<bool>> dp(lenp,
            std::vector<bool>(lens));

        for (int i = 0; i < lenp; ++i) {
            for (int j = 0; j < lens; ++j) {
                bool match = false;

                if (p[i] == s[j] || p[i] == '.') {
                    match = (i && j ? dp[i - 1][j - 1] : !i && !j);
                } else if (p[i] == '*' &&
                    (p[i - 1] == s[j] || p[i - 1] == '.')) {
                    match = (j ? dp[i][j - 1] : true);
                }

                dp[i][j] = match;

                // std::cout << dp[i][j] << " ";
            }
            // std::cout << std::endl;
        }

        return dp.back().back();
    }
};
