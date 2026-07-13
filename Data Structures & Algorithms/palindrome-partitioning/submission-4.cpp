class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<string>> result;

        const int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));

        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] &&
                    (i + 1 > i + l - 2 || dp[i + 1][i + l - 2]));
            }
        }

        std::vector<std::string> curr;
        dfs(result, s, 0, curr, dp);

        return result;
    }

private:
    void dfs(std::vector<std::vector<string>>& result,
        const std::string& s, int i,
        std::vector<std::string>& curr,
        const std::vector<std::vector<bool>>& dp) {
        if (i >= s.size()) {
            result.emplace_back(curr);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (dp[i][j]) {
                curr.emplace_back(s.substr(i, j - i + 1));
                dfs(result, s, j + 1, curr, dp);
                curr.pop_back();
            }
        }
    }
};
