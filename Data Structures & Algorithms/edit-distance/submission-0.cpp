class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.size();
        const int len2 = word2.size();

        const int cInf = std::numeric_limits<int>::max();

        std::vector<std::vector<int>> dp(len1 + 1,
            std::vector<int>(len2 + 1, cInf));

        dp[0][0] = 0;

        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (!i && !j) continue;

                dp[i][j] = std::min({
                    (i ? dp[i - 1][j] : 0) + 1,
                    (j ? dp[i][j - 1] : 0) + 1,
                    (i && j ? dp[i - 1][j - 1] : 0) + (i && j && word1[i - 1] != word2[j - 1])});
                // else
                //     ;

                // std::cout << dp[i][j] << " ";
            }

            std::cout << std::endl;
        }

        return dp[len1][len2];
    }
};
