class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);
        diag_1.resize(3 * n);
        diag_2.resize(3 * n);
        std::vector<std::vector<std::string>> res;

        std::vector<std::string> cur(n,
            std::string(n, '.'));
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

        for (int x = 0; x < n; ++x) {
            if (col[x] ||
                diag_1[x - y + n] ||
                diag_2[x + y]) continue;

            col[x] = true;
            diag_1[x - y + n] = true;
            diag_2[x + y] = true;

            cur[y][x] = 'Q';
            dfs(res, y + 1, n, cur);
            cur[y][x] = '.';

            col[x] = false;
            diag_1[x - y + n] = false;
            diag_2[x + y] = false;
        }
    }

    std::vector<bool> diag_1;  // to the right bottom
    std::vector<bool> diag_2;  // to the left bottom
    std::vector<bool> col;
};
