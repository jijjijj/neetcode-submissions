class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        std::vector<std::vector<bool>> vis(m,
            std::vector<bool>(n, false));

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (!vis[y][x] && board[y][x] == 'O') {
                    std::vector<std::pair<int, int>> to_fill =
                        bfs(board, vis, x, y, m, n);

                    for (const auto& c : to_fill) {
                        board[c.second][c.first] = 'X';
                    }
                }
            }
        }
    }

private:
    std::vector<std::pair<int, int>> bfs(
        const vector<vector<char>>& board,
        std::vector<std::vector<bool>>& vis,
        int x, int y, int m, int n) {

        std::queue<std::pair<int, int>> q; // x, y
        q.push(std::pair{ x, y });

        std::vector<std::pair<int, int>> res;

        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        bool bad = false;
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            vis[cy][cx] = true;
            res.emplace_back(std::pair{ cx, cy });

            for (const auto& c : coords) {
                const int nx = cx + c.first;
                const int ny = cy + c.second;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    bad = true;
                    continue;
                }
                if (vis[ny][nx] || board[ny][nx] == 'X') continue;

                q.push(std::pair{ nx, ny });
            }
        }

        return bad ? decltype(res){} : res;
    }
};
