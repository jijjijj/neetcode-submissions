class Dsu {
public:
    explicit Dsu(int n) : _parent(n), _size(n, 1), _comps{n} {
        for (int i = 0; i < n; ++i) _parent[i] = i;
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        --_comps;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _size[b];
    }

    int sets() {
        return _comps;
    }

private:
    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

    std::vector<int> _parent;
    std::vector<int> _size;
    int _comps = 0;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Dsu dsu{ n };

        for (const auto& edge : edges) {
            dsu.union_sets(edge[0], edge[1]);
        }

        return dsu.sets();
    }
};
