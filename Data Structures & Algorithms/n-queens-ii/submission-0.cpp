class Solution {
public:
    int totalNQueens(int n) {
        // diag1 = col = {};
        // diag1.resize(n, false);
        // diag2.resize(2 * n);
        // col.resize(n, false);
        return dfs(0, n);
    }

private:
    int dfs(int y, int n) {
        if (y == n) {
            // std::cout << 1;
            return 1;
        }

        int ans = 0;
        for (int x = 0; x < n; ++x) {
            if (diag1.contains(x + y) || diag2.contains(y - x) || col.contains(x)) continue;
            diag1.emplace(x + y);
            diag2.emplace(y - x);
            col.emplace(x);
            ans += dfs(y + 1, n);
            diag1.erase(x + y);
            diag2.erase(y - x);
            col.erase(x);
        }

        return ans;
    }

    std::unordered_set<int> diag1;
    std::unordered_set<int> diag2;
    std::unordered_set<int> col;
};