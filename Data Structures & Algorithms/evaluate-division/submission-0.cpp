class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
        vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string,
            std::vector<std::pair<std::string, double>>> e;
        for (int i = 0; i < equations.size(); ++i) {
            const auto& edge = equations[i];

            e[edge[0]].emplace_back(std::pair{ edge[1], values[i] });
            e[edge[1]].emplace_back(std::pair{ edge[0], 1.0 / values[i] });
        }

        std::vector<double> res;

        for (const auto& q : queries) {
            const auto& a = q[0];
            const auto& b = q[1];

            if (!e.contains(a) || !e.contains(b)) {
                res.emplace_back(-1.0);
                continue;
            }

            if (a == b) {
                res.emplace_back(1.0);
                continue;
            }

            std::unordered_set<std::string> vis;
            res.emplace_back(dfs(a, b, e, vis).value_or(-1.0));
        }

        return res;
    }

private:
    std::optional<double> dfs(const std::string& a, const std::string& b,
        std::unordered_map<std::string,
            std::vector<std::pair<std::string, double>>>& e,
        std::unordered_set<std::string>& vis) {
        if (a == b) return 1.0;

        vis.emplace(a);

        for (const auto& [to, w] : e[a]) {
            if (vis.contains(to)) continue;

            const std::optional<double> r = dfs(to, b, e, vis);
            if (!r) continue;
            return w * *r;
        }

        return {};
    }
};