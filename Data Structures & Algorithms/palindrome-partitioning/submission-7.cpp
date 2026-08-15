class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();

        dp = std::vector<std::vector<bool>>(n + 1,
            std::vector<bool>(n));
        dp[0][0] = true;

        for (int l = 1; l <= n; ++l) {
            for (int j = 0; j <= n - l; ++j) {
                dp[l][j] = (l == 1 ||
                    (s[j] == s[j + l - 1] && (l == 2 || dp[l - 2][j + 1])));
            }
        }

        dfs(s, 0);

        return res;
    }

private:
    void dfs(const std::string& s, int i) {
        if (i == s.size()) {
            res.emplace_back(cur);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (dp[j - i + 1][i]) {
                cur.emplace_back(
                    s.substr(i, j - i + 1));
                dfs(s, j + 1);
                cur.pop_back();
            }
        }
    }

    std::vector<std::vector<bool>> dp;
    std::vector<std::string> cur;
    std::vector<std::vector<string>> res;
};
