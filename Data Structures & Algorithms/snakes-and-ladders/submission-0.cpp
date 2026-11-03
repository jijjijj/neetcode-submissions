class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size();

        std::vector<std::vector<int>> e(n * n + 1);

        std::unordered_map<int, int> to;
        // for (int i = 1; i <= n * n; ++i) to[i] = i + 1;

        int curr = 1;
        for (int y = n - 1; y >= 0; --y) {
            for (int x = 0; x < n; ++x) {
                const int effx = ((n - y) & 1) ? x : n - x - 1;
                if (board[y][effx] != -1) {
                    to[curr] = board[y][effx];
                }
                ++curr;
            }
        }

        for (int i = 1; i <= n * n; ++i) {
            for (int j = i + 1; j <= std::min(i + 6, n * n); ++j) {
                if (!to.contains(j)) {
                    e[i].emplace_back(j);
                } else {
                    e[i].emplace_back(to[j]);
                }
            }
        }

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

                for (const int to : e[v]) {
                    if (!vis[to]) {
                        vis[to] = true;
                        q.push(to);
                    }
                }
            }
            ++dist;
        }

        return -1;
    }
};
