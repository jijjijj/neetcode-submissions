class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        std::vector<std::vector<int>> dp(n,
            std::vector<int>(n));

        int maxi = 0;
        int maxl = 0;
        int maxd = 0;

        for (int l = 1; l <= n; ++l) {
            for (int i = n - l; i >= 0; --i) {
                dp[i][i + l - 1] = 
                    s[i] == s[i + l - 1] &&
                    (l <= 2 || dp[i + 1][i + l - 2]);
                
                if (l > maxl && dp[i][i + l - 1]) {
                    maxi = i;
                    maxl = l;
                }
            }
        }

        return s.substr(maxi, maxl);
    }
};
