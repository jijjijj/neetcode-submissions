class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.size();
        const int len2 = word2.size();

        const int cInf = std::numeric_limits<int>::max();

        std::vector<std::vector<int>> dp(len1 + 1,
            std::vector<int>(len2 + 1, 0));

        for (int i = 0; i <= len1; ++i) dp[i][len2] = len1 - i;
        for (int j = 0; j <= len2; ++j) dp[len1][j] = len2 - j;

        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + std::min({
                        dp[i][j + 1],
                        dp[i + 1][j],
                        dp[i + 1][j + 1]
                    });
                }
            }
        }

        return dp[0][0];
    }
};
