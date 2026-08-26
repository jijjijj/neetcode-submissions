class Solution {
public:
    // dfs (hashset)
    // dfs (memoization)
    // +khan's
    // floyd-warshall
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {
        std::vector<std::vector<int>> e(numCourses);
        for (const auto& edge : prerequisites) {
            e[edge[1]].emplace_back(edge[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            dfs(i, -1, e);
        }

        std::vector<bool> res;
        for (const auto& q : queries) {
            res.emplace_back(prereq[q[1]].contains(q[0]));
        }
        return res;
    }

private:
    void dfs(int v, int p,
        const std::vector<std::vector<int>>& e) {
        if (prereq.contains(v)) {
            return;
        }

        std::unordered_set<int> res;
        
        for (const int to : e[v]) {
            if (to == p) continue;

            dfs(to, v, e);
            res.insert(prereq[to].begin(), prereq[to].end());
        }

        res.emplace(v);
        prereq[v] = res;
    }

    std::unordered_map<int,
        std::unordered_set<int>> prereq;
};