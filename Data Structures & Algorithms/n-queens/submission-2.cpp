class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;

        std::vector<std::string> cur;
        dfs(res, 0, n, cur);

        return res;
    }

private:
    void dfs(
        std::vector<std::vector<std::string>>& res,
        int y, int n, std::vector<std::string>& cur) {
        if (y == n) {
            res.emplace_back(cur);
            return;
        }
        
        cur.emplace_back(std::string(n, '.'));

        for (int x = 0; x < n; ++x) {
            if (col.contains(x) ||
                diag_1.contains(x - y) ||
                diag_2.contains(x + y)) continue;

            col.emplace(x);
            diag_1.emplace(x - y);
            diag_2.emplace(x + y);

            cur.back()[x] = 'Q';
            dfs(res, y + 1, n, cur);
            cur.back()[x] = '.';

            col.erase(x);
            diag_1.erase(x - y);
            diag_2.erase(x + y);
        }

        cur.pop_back();
    }

    std::unordered_set<int> diag_1;  // to the right bottom
    std::unordered_set<int> diag_2;  // to the left bottom
    std::unordered_set<int> col;
};
