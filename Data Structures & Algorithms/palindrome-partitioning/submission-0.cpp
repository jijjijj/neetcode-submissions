class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<string>> result;
        std::vector<std::string> curr;
        dfs(result, s, 0, 0, curr);

        return result;
    }

private:
    void dfs(std::vector<std::vector<string>>& result,
        const std::string& s, int l, int r,
        std::vector<std::string>& curr) {
        if (r >= s.size()) {
            if (l == r) result.emplace_back(curr);
            return;
        }

        bool is_palindrome = true;
        for (int i = 0; i < r - l + 1; ++i) {
            if (s[l + i] != s[r - i]) {
                is_palindrome = false;
                break;
            }
        }

        // std::cout << l << " " << r << " " << is_palindrome << std::endl;

        if (is_palindrome) {
            curr.emplace_back(s.substr(l, r - l + 1));
            dfs(result, s, r + 1, r + 1, curr);
            curr.pop_back();
        }

        dfs(result, s, l, r + 1, curr);
    }
};
