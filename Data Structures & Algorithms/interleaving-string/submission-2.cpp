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

        dp[0][0] = true;

        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (!i && !j) continue;

                const char a = s1[i - 1];
                const char b = s2[j - 1];
                const char c = s3[i + j - 1];

                dp[i][j] = (i ? dp[i - 1][j] && a == c : false) ||
                    (j ? dp[i][j - 1] && b == c : false);
            }
        }

        return dp[len1][len2];
    }
};
