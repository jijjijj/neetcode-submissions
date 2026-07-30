class Dsu {
public:
    explicit Dsu(int n) : _parent(n, 0), _size(n, 1) {
        for (int i = 0; i < n; ++i) _parent[i] = i;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _size[b];

        return true;
    }

    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

private:
    std::vector<int> _parent;
    std::vector<int> _size;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        std::vector<std::tuple<int, int, int>> e; // dist, i, j

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int dist = std::abs(points[i][0] - points[j][0]) +
                    std::abs(points[i][1] - points[j][1]);
                
                e.emplace_back(std::tuple{ dist, i, j });
            }
        }

        std::ranges::sort(e);

        int answer = 0;

        Dsu dsu(n);
        for (const auto [_, i, j] : e) {
            if (dsu.union_sets(i, j)) {
                answer += _;
            }
        }

        return answer;
    }
};
