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

        for (int y = sy; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                bool valid = true;
                for (const auto& coord : curr) {
                    if (coord.first == x ||
                        coord.second == y ||
                        std::abs(coord.first - x) ==
                            std::abs(coord.second - y)) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                curr.emplace_back(std::pair{ x, y });
                dfs(res, n, curr, x + 1, y + 1);
                curr.pop_back();
            }
        }
    }
};
