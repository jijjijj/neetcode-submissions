class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int len1 = text1.size();
        const int len2 = text2.size();

        std::vector<std::vector<int>> dp(len1,
            std::vector<int>(len2));

        int max = 0;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                dp[i][j] = std::max((i ? dp[i - 1][j] : 0),
                    (((i && j) ? dp[i - 1][j - 1] : 0) +
                        (text1[i] == text2[j])));
                max = std::max(max, dp[i][j]);
            }
        }

        return max;
    }
};
