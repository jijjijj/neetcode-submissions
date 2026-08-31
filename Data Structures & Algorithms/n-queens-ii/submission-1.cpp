class Solution {
public:
    int totalNQueens(int n) {
        diag1 = diag2 = col = {};
        diag1.resize(2 * n, false);
        diag2.resize(2 * n, false);
        col.resize(n, false);
        return dfs(0, n);
    }

private:
    int dfs(int y, int n) {
        if (y == n) {
            return 1;
        }

        int ans = 0;
        for (int x = 0; x < n; ++x) {
            if (diag1[x + y] || diag2[n + y - x] || col[x]) continue;
            diag1[x + y] = true;
            diag2[n + y - x] = true;
            col[x] = true;
            ans += dfs(y + 1, n);
            diag1[x + y] = false;
            diag2[n + y - x] = false;
            col[x] = false;
        }

        return ans;
    }

    std::vector<bool> diag1;
    std::vector<bool> diag2;
    std::vector<bool> col;
};