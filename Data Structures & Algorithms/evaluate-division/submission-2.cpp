class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
        vector<double>& values, vector<vector<string>>& queries) {
        std::unordered_map<std::string,
            std::unordered_map<std::string, double>> e;

        for (int i = 0; i < equations.size(); ++i) {
            const auto& edge = equations[i];
            e[edge[0]][edge[1]] = values[i];
            e[edge[1]][edge[0]] = 1.0 / values[i];
        }
        
        for (const auto& [k, _] : e) {
            for (const auto& [i, w1] : e[k]) {
                for (const auto& [j, w2] : e[k]) {
                    e[i][j] = e[i][k] * e[k][j];
                }
            }
        }

        std::vector<double> res;

        for (const auto& q : queries) {
            const auto& a = q[0];
            const auto& b = q[1];

            if (!e.contains(a) || !e.contains(b) || !e[a].contains(b)) {
                res.emplace_back(-1.0);
            } else {
                res.emplace_back(e[a][b]);
            }
        }

        return res;
    }
};