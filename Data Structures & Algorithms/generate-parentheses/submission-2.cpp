class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;

        std::string s;
        dfs(result, n * 2, 0, s);

        return result;
    }

private:
    void dfs(std::vector<string>& result, int n, int open,
        std::string& str) {
        if (str.size() == n) {
            if (!open) result.emplace_back(str);
            return;
        }

        if (open) {
            str.push_back(')');
            dfs(result, n, open - 1, str);
            str.pop_back();
        }

        str.push_back('(');
        dfs(result, n, open + 1, str);
        str.pop_back();
    }
};
