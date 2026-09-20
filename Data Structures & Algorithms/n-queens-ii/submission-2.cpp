class Solution {
public:
    int totalNQueens(int n) {
        return dfs(0, n);
    }

private:
    int dfs(int y, int n) {
        if (y == n) {
            return 1;
        }

        int ans = 0;
        for (int x = 0; x < n; ++x) {
            if ((diag1 & (1 << (x + y))) ||
                (diag2 & (1 << (n + y - x))) ||
                (col & (1 << x))) continue;
            diag1 |= (1 << (x + y));
            diag2 |= (1 << (n + y - x));
            col |= (1 << x);
            ans += dfs(y + 1, n);
            diag1 ^= (1 << (x + y));
            diag2 ^= (1 << (n + y - x));
            col ^= (1 << x);
        }

        return ans;
    }

    int diag1{};
    int diag2{};
    int col{};
};