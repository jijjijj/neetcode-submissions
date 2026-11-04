class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();

        int dist = 0;
        std::vector<bool> vis(n * n + 1);
        vis[1] = true;
        std::queue<int> q;
        q.push(1);

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                const int v = q.front();
                q.pop();

                if (v == n * n) return dist;

                for (int j = v + 1; j <= std::min(n * n, v + 6); ++j) {
                    const int ny = n - ((j - 1) / n) - 1;
                    int nx = (j - 1) % n;
                    if ((n - ny) % 2 == 0) nx = n - nx - 1;

                    int t = j;
                    if (board[ny][nx] != -1) t = board[ny][nx];

                    if (!vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
            ++dist;
        }

        return -1;
    }
};
