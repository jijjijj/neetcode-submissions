class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::pair<int, int>> curr;

        dfs(res, n, curr, 0, 0);

        return res;
    }

private:
    void dfs(std::vector<std::vector<std::string>>& res, int n,
        std::vector<std::pair<int, int>>& curr, int sx, int sy) {
        if (curr.size() == n) {
            std::vector<std::string> grid(n, std::string(n, '.'));

            for (const auto& coord : curr) {
                grid[coord.second][coord.first] = 'Q';
            }

            res.emplace_back(std::move(grid));

            return;
        }

        for (int x = 0; x < n; ++x) {
            bool valid = true;
            for (const auto& coord : curr) {
                if (coord.first == x ||
                    std::abs(coord.first - x) ==
                        std::abs(coord.second - sy)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            curr.emplace_back(std::pair{ x, sy });
            dfs(res, n, curr, x + 1, sy + 1);
            curr.pop_back();
        }
    }
};
