class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int len1 = text1.size();
        const int len2 = text2.size();

        std::vector<int> dp(len2 + 1);

        for (int i = len1 - 1; i >= 0; --i) {
            std::vector<int> nw = dp;
            for (int j = len2 - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    nw[j] = 1 + dp[j + 1];
                } else {
                    nw[j] = std::max(nw[j], dp[j + 1]);
                }
            }
            dp = std::move(nw);
        }

        return dp[0];
    }
};
