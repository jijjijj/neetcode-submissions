class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();

        dp = std::vector<std::vector<bool>>(n + 1,
            std::vector<bool>(n));

        for (int l = 1; l <= n; ++l) {
            for (int j = 0; j <= n - l; ++j) {
                dp[l][j] = (l == 1 ||
                    (s[j] == s[j + l - 1] && (l == 2 || dp[l - 2][j + 1])));
            }
        }

        return dfs(s, 0);
    }

private:
    std::vector<std::vector<std::string>>
        dfs(const std::string& s, int i) {
        if (i == s.size()) {
            return {{}};
        }

        std::vector<std::vector<std::string>> res;
        for (int j = i; j < s.size(); ++j) {
            if (dp[j - i + 1][i]) {
                auto next = dfs(s, j + 1);
                
                for (auto& p : next) {
                    p.insert(p.begin(), s.substr(i, j - i + 1));
                }
                
                res.insert(res.end(), next.begin(), next.end());
            }
        }
        return res;
    }

    std::vector<std::vector<bool>> dp;
};
