class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const size_t n = s.size();
        
        std::vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1 + dp[i + 1];
            for (const auto& word : dictionary) {
                if (i + word.size() > n) continue;
                bool flag = true;
                for (int j = i; j < i + word.size(); ++j) {
                    if (s[j] != word[j - i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    dp[i] = std::min(dp[i], dp[i + word.size()]);
                }
            }
        }

        return dp.front();
    }
};