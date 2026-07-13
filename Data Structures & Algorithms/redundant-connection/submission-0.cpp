class Dsu {
public:
    explicit Dsu(int n) : _size(n, 1), _parent(n, 0) {
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _size[b];
    }

    bool is_same(int a, int b) {
        a = find(a);
        b = find(b);

        return a == b;
    }

private:
    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

    std::vector<int> _size;
    std::vector<int> _parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;

        for (const auto& edge : edges)
            n = std::max(n, std::max(edge[0], edge[1]));

        Dsu dsu{ n };

        int to_remove = 0;
        for (int i = 0; i < edges.size(); ++i) {
            const auto& edge = edges[i];

            const int v1 = edge[0] - 1;
            const int v2 = edge[1] - 1;

            if (dsu.is_same(v1, v2)) {
                to_remove = i;
            } else dsu.union_sets(v1, v2);
        }

        return edges[to_remove];
    }
};
