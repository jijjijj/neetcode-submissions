class Dsu {
public:
    explicit Dsu(int n) : _parent(n, 0), _size(n, 1) {
        for (int i = 0; i < n; ++i) _parent[i] = i;
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _size[b];
    }

    bool is_connected(int a, int b) {
        a = find(a);
        b = find(b);

        return a == b;
    }

private:
    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

    std::vector<int> _parent;
    std::vector<int> _size;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        Dsu dsu(m * n + 1);

        const auto index = [n](int x, int y) { return y * n + x; };
        const int dummy = m * n;

        const std::vector<std::pair<int, int>> coords = {
            { 1, 0 }, { 0, 1 }//, { -1, 0 }, { 0, -1 }
        };

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (board[y][x] == 'O') {
                    if (!x || !y || y == m - 1 || x == n - 1) {
                        dsu.union_sets(index(x, y), dummy);
                    }
                    
                    for (const auto& c : coords) {
                        const int cx = x + c.first;
                        const int cy = y + c.second;

                        if (cx < 0 || cy < 0 || cx >= n ||
                            cy >= m || board[cy][cx] != 'O') continue;
                        
                        dsu.union_sets(index(cx, cy), index(x, y));
                    }
                }
            }
        }

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (board[y][x] == 'O') {
                    if (!dsu.is_connected(index(x, y), dummy)) {
                        board[y][x] = 'X';
                    }
                }
            }
        }
    }
};
