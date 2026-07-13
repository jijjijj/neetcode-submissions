#include <ranges>
#include <vector>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));

        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] &&
                    (i + 1 > i + l - 2 || dp[i + 1][i + l - 2]));
            }
        }

        return dfs(s, 0, dp);
    }

private:
    vector<vector<string>> dfs(const std::string& s, int i,
        const std::vector<std::vector<bool>>& dp) {
        if (i >= s.size()) {
            return {{}};
        }

        vector<vector<string>> ret;
        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                auto ext = dfs(s, j + 1, dp);

                for (auto& p : ext) {
                    std::vector<std::string> curr;
                    curr.emplace_back(s.substr(i, j - i + 1));
                    curr.insert(curr.end(), p.begin(), p.end());
                    ret.emplace_back(std::move(curr));
                }
            }
        }
        return ret;
    }
};
