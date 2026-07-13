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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() + 1;

        Dsu dsu{ n };
        for (const auto& edge : edges) {
            if (!dsu.union_sets(edge[0], edge[1])) {
                return edge;
            }
        }

        return { -1, -1 };
    }
};
