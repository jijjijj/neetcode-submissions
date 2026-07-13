class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        std::vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (const auto& word : words) {
                if (i >= word.size() && dp[i - word.size()] &&
                    s.substr(i - word.size(), word.size()) == word) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};
