class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        int maxl = 0;

        std::vector<std::vector<bool>> dp(s.size(),
            std::vector<bool>(s.size()));

        for (int i = 0; i < s.size(); ++i) {
            for (int l = 1; l <= s.size() - i; ++l) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] &&
                    (i + 1 >= i + l - 2 || dp[i + 1][i + l - 2]));

                if (l > maxl && dp[i][i + l - 1]) {
                    maxi = i;
                    maxl = l;
                }
            }
        }

        return s.substr(maxi, maxl);
    }
};
