class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        int maxl = 0;

        std::vector<std::vector<bool>> dp(s.size(),
            std::vector<bool>(s.size()));

        for (int j = 0; j < s.size(); ++j) {
            for (int i = j; i >= 0; --i) {
                dp[i][j] = (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1]));

                // std::cout << i << " " << (i + l - 1) << ": " << s.substr(i, l) << " = " << dp[i][i + l - 1] << std::endl;

                if (j - i + 1 > maxl && dp[i][j]) {
                    maxi = i;
                    maxl = j - i + 1;
                }
            }
        }

        return s.substr(maxi, maxl);
    }
};
