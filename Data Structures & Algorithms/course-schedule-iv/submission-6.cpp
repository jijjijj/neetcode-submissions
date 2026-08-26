class Solution {
public:
    // +dfs (hashset)
    // dfs (memoization)
    // +khan's
    // floyd-warshall
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {
        prereq.resize(numCourses);
        std::vector<std::vector<int>> e(numCourses);
        for (const auto& edge : prerequisites) {
            e[edge[0]].emplace_back(edge[1]);
        }

        std::vector<bool> res;
        for (const auto& q : queries) {
            res.emplace_back(dfs(q[0], q[1], -1, e));
        }
        return res;
    }

private:
    bool dfs(int v1, int v2, int p,
        const std::vector<std::vector<int>>& e) {
        if (prereq[v1].contains(v2)) {
            return prereq[v1][v2];
        }
        if (v1 == v2) {
            prereq[p][v2] = true;
            return true;
        }

        for (const int to : e[v1]) {
            if (to == p) continue;

            if (dfs(to, v2, v1, e)) {
                prereq[v1][v2] = true;
                return true;
            }
        }

        prereq[v1][v2] = 0;
        return false;
    }

    std::vector<
        std::unordered_map<int, int>> prereq;
};