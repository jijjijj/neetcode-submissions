class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<string>> result;
        std::vector<std::string> curr;
        dfs(result, s, 0, curr);

        return result;
    }

private:
    void dfs(std::vector<std::vector<string>>& result,
        const std::string& s, int i,
        std::vector<std::string>& curr) {
        if (i >= s.size()) {
            result.emplace_back(curr);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (is_palindrome(s, i, j)) {
                curr.emplace_back(s.substr(i, j - i + 1));
                dfs(result, s, j + 1, curr);
                curr.pop_back();
            }
        }
    }

    bool is_palindrome(const std::string& s, int p1, int p2) {
        for (int i = 0; i < p2 - p1 + 1; ++i) {
            if (s[p1 + i] != s[p2 - i]) {
                return false;
            }
        }
        return true;
    }
};
