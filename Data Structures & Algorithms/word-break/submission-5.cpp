class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string_view> words(
            wordDict.begin(), wordDict.end());

        const int n = s.size();
        std::vector<bool> dp(n + 1);
        dp[n] = true;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!dp[j]) continue;

                std::string_view str = s;
                str = str.substr(i, j - i);

                if (words.contains(str)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
