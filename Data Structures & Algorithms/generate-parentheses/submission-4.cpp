class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, n);

        return res;
    }

private:
    void dfs(int opened, int n) {
        if (cur.size() == n * 2) {
            res.emplace_back(cur);
            return;
        }

        if (opened < (n * 2 - cur.size())) {
            cur.push_back('(');
            dfs(opened + 1, n);
            cur.pop_back();
        }

        if (opened > 0) {
            cur.push_back(')');
            dfs(opened - 1, n);
            cur.pop_back();
        }
    }

    std::string cur;
    std::vector<std::string> res;
};
