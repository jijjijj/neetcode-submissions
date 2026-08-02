class Solution {
public:
    int numDistinct(string s, string t) {
        const int lens = s.size();
        const int lent = t.size();

        std::vector<int> dp(lens + 1);

        dp[lens] = 1;

        for (int i = lent; i >= 0; --i) {
            int last = dp.back();
            if (i < lent) dp[lens] = 0;
            for (int j = lens - 1; j >= 0; --j) {
                int cur = dp[j];
                dp[j] = dp[j + 1];
                if (t[i] == s[j]) {
                    dp[j] += last;
                }
                last = cur;
            }
        }

        return dp.front();
    }
};