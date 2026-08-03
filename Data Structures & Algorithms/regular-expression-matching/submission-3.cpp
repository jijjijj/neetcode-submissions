class Solution {
public:
    bool isMatch(string s, string p) {
        const int lenp = p.size();
        const int lens = s.size();

        std::vector<bool> dp(lenp + 1);

        dp[lenp] = true;
        
        for (int j = lens; j >= 0; --j) {
            bool prev = dp.back();
            for (int i = lenp - 1; i >= 0; --i) {
                bool cur = dp[i];
                const bool match = j < lens &&
                    (s[j] == p[i] || p[i] == '.');
                
                if (i + 1 < lenp && p[i + 1] == '*') {
                    dp[i] = dp[i + 2];
                    if (match) {
                        dp[i] = cur || dp[i];
                    }
                } else if (match) {
                    dp[i] = prev;//dp[i + 1][j + 1];
                }
                prev = cur;
            }
        }

        return dp[0];
    }
};
