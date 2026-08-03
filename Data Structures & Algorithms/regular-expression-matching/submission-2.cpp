class Solution {
public:
    bool isMatch(string s, string p) {
        const int lenp = p.size();
        const int lens = s.size();

        std::vector<std::vector<bool>> dp(lenp + 1,
            std::vector<bool>(lens + 1));

        dp[lenp][lens] = true;
        
        for (int i = lenp - 1; i >= 0; --i) {
            for (int j = lens; j >= 0; --j) {
                const bool match = j < lens &&
                    (s[j] == p[i] || p[i] == '.');
                
                if (i + 1 < lenp && p[i + 1] == '*') {
                    dp[i][j] = dp[i + 2][j];
                    if (match) {
                        dp[i][j] = dp[i][j + 1] || dp[i][j];
                    }
                } else if (match) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
