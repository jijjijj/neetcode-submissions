class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // std::unordered_set<std::string> words(
        //     wordDict.begin(), wordDict.end());

        const int n = s.size();
        std::vector<bool> dp(n + 1);
        dp[n] = true;

        // 0123|4
        // ++++|1
        for (int i = n - 1; i >= 0; --i) {
            for (const auto& w : wordDict) {
                if (i + w.size() <= n && dp[i + w.size()] &&
                    s.substr(i, w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
