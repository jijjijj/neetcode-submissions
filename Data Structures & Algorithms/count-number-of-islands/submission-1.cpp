class Dsu {
public:
    void make_set(int v) {
        parent[v] = v;
        _size[v] = 1;
        ++count;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b || !a || !b) return;
        if (_size[a] < _size[b]) std::swap(a, b);

        parent[b] = a;
        _size[a] += _size[b];
        --count;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    int size() {
        return count;
    }

private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> _size;
    int count{};
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        Dsu dsu{};

        const auto index = [&grid](int x, int y)
            { return grid[0].size() * y + x; };

        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                if (grid[y][x] == '1') {
                    const int ind = index(x, y);
                    dsu.make_set(ind);
                    dsu.union_sets(ind, index(x + 1, y));
                    dsu.union_sets(ind, index(x - 1, y));
                    dsu.union_sets(ind, index(x, y + 1));
                    dsu.union_sets(ind, index(x, y - 1));
                }
            }
        }

        return dsu.size();
    }
};
