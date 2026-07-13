class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        std::queue<std::pair<int, int>> q; // x, y
        for (int x = 0; x < n; ++x) {
            if (board[0][x] == 'O') q.push(std::pair{ x, 0 });
            if (board[m - 1][x] == 'O') q.push(std::pair{ x, m - 1 });
        }

        for (int y = 0; y < m; ++y) {
            if (board[y][0] == 'O') q.push(std::pair{ 0, y });
            if (board[y][n - 1] == 'O') q.push(std::pair{ n - 1, y });
        }

        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }
        };

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            board[cy][cx] = '.';

            for (const auto& c : coords) {
                const int nx = cx + c.first;
                const int ny = cy + c.second;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
                    board[ny][nx] != 'O') continue;

                q.push(std::pair{ nx, ny });
            }
        }

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (board[y][x] == '.') {
                    board[y][x] = 'O';
                } else {
                    board[y][x] = 'X';
                }
            }
        }
    }
};
