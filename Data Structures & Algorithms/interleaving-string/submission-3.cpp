class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j] = is it possible to form s3[:i+j] 
        // by interleaving s1[:i] and s2[:j]
        const int len1 = s1.size();
        const int len2 = s2.size();

        if (s3.size() != len1 + len2) return false;

        std::vector<std::vector<int>> dp(len1 + 1,
            std::vector<int>(len2 + 1));

        dp[len1][len2] = true;

        for (int i = len1; i >= 0; --i) {
            for (int j = len2; j >= 0; --j) {
                if (i < len1 && s1[i] == s3[i + j] && dp[i + 1][j]) dp[i][j] = true;
                if (j < len2 && s2[j] == s3[i + j] && dp[i][j + 1]) dp[i][j] = true;
            }
        }

        return dp[0][0];
    }
};
