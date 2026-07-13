class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> dp(s.size());

        std::unordered_set<std::string> allowed;
        for (int i = 1; i <= 26; ++i) {
            allowed.emplace(std::to_string(i));
        }

        for (int i = 0; i < s.size(); ++i) {
            if (allowed.contains(s.substr(i, 1))) {
                dp[i] = i > 0 ? dp[i - 1] : 1;
            }
            if (i > 0 && allowed.contains(s.substr(i - 1, 2))) {
                dp[i] += i > 1 ? dp[i - 2] : 1;
            }
            
            if (!dp[i]) return 0;
            // std::cout << dp[i] << " ";
        }

        return dp.back();
    }
};
