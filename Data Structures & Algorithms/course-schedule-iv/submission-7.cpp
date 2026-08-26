class Solution {
public:
    // +dfs (hashset)
    // +dfs (memoization)
    // +khan's
    // floyd-warshall
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {
        std::vector<std::vector<bool>> m(numCourses,
            std::vector<bool>(numCourses));

        for (const auto& edge : prerequisites) {
            m[edge[0]][edge[1]] = 1;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    m[i][j] = m[i][j] || (m[i][k] && m[k][j]);
                }
            }
        }

        std::vector<bool> res;
        for (const auto& q : queries) {
            res.emplace_back(m[q[0]][q[1]]);
        }
        return res;
    }
};