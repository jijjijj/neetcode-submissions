class Dsu {
public:
    explicit Dsu(int n) : _parent(n), _size(n, 1), _comp{ n } {
        for (int i = 0; i < n; ++i) _parent[i] = i;
    }

    bool union_sets(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        --_comp;
        if (_size[a] < _size[b]) std::swap(a, b);

        _parent[b] = a;
        _size[a] += _parent[b];

        return true;
    }

    int sets() {
        return _comp;
    }

private:
    int find(int v) {
        if (v == _parent[v]) return v;

        return _parent[v] = find(_parent[v]);
    }

    std::vector<int> _parent;
    std::vector<int> _size;
    int _comp = 0;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        std::vector<std::vector<int>> e(n);
        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        Dsu dsu{n};

        for (const auto& edge : edges) {
            if (!dsu.union_sets(edge[0], edge[1])) {
                return false;
            }
        }

        return dsu.sets() == 1;
    }
};
