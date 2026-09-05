class DSU {
public:
    void add(const std::string& v) {
        if (!parent.contains(v)) {
            parent[v] = v;
            w[v] = 1.0;
        }
    }

    std::string find(const std::string& v) {
        if (parent[v] != v) {
            std::string orig = parent[v];
            parent[v] = find(parent[v]);
            w[v] *= w[orig];
        }

        return parent[v];
    }

    void union_sets(std::string a, std::string b, double val) {
        add(a);
        add(b);

        const std::string roota = find(a);
        const std::string rootb = find(b);

        if (a != b) {
            parent[roota] = rootb;
            w[roota] = val * w[b] / w[a];
        }
    }

    double ratio(const std::string& a, const std::string& b) {
        if (!parent.contains(a) || !parent.contains(b) ||
            find(a) != find(b)) {
            return -1.0;
        }

        return w[a] / w[b];
    }

private:
    std::unordered_map<std::string,
        double> w;
    std::unordered_map<std::string,
        std::string> parent;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
        vector<double>& values, vector<vector<string>>& queries) {
        DSU dsu{};

        for (int i = 0; i < equations.size(); ++i) {
            const auto& edge = equations[i];
            dsu.union_sets(edge[0], edge[1], values[i]);
        }

        std::vector<double> res;

        for (const auto& q : queries) {
            const auto& a = q[0];
            const auto& b = q[1];

            res.emplace_back(dsu.ratio(a, b));
        }

        return res;
    }
};