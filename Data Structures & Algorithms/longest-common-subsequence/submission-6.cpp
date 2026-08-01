class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int len1 = text1.size();
        const int len2 = text2.size();

        std::vector<int> dp(len2 + 1);

        for (int i = len1 - 1; i >= 0; --i) {
            int lat = 0;
            for (int j = len2 - 1; j >= 0; --j) {
                int nlat = dp[j];
                if (text1[i] == text2[j]) {
                    dp[j] = 1 + lat;
                } else {
                    dp[j] = std::max(dp[j], dp[j + 1]);
                }
                lat = nlat;
            }
        }

        return dp[0];
    }
};
