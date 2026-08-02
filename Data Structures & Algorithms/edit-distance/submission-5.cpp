class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.size();
        const int len2 = word2.size();

        std::vector<int> dp(len2 + 1, 0);

        for (int j = 0; j <= len2; ++j) dp[j] = len2 - j;

        for (int i = len1 - 1; i >= 0; --i) {
            int prev = dp.back();
            dp[len2] = len1 - i;
            for (int j = len2 - 1; j >= 0; --j) {
                int temp = dp[j];
                if (word1[i] == word2[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + std::min({
                        dp[j + 1],
                        dp[j],
                        prev
                    });
                }
                prev = temp;
            }
        }

        return dp[0];
    }
};
