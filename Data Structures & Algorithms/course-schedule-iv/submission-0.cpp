class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {
        // std::unordered_set<int> track;
        // for (const auto& q : queries) {
        //     track.emplace(q[0]);
        // }

        std::unordered_map<int, int> indeg;
        std::vector<std::vector<int>> e(numCourses);
        for (const auto& edge : prerequisites) {
            e[edge[0]].emplace_back(edge[1]);
            indeg[edge[0]];
            ++indeg[edge[1]];
        }

        std::queue<std::pair<int, int>> q;
        // std::unordered_set<int> tracking;
        for (const auto& [v, f] : indeg) {
            if (!f) {
                q.push({ v, v });
                // if (track.contains(v)) tracking.emplace(v);
            }
        }

        std::vector<std::vector<bool>> m(numCourses,
            std::vector<bool>(numCourses));
        
        while (!q.empty()) {
            const auto [o, v] = q.front();
            q.pop();

            m[o][v] = true;

            for (const int to : e[v]) {
                q.push({ o, to });
            }
        }

        std::vector<bool> res;

        for (const auto& q : queries) {
            res.emplace_back(m[q[0]][q[1]]);
        }

        return res;
    }
};