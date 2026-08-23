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

        std::queue<int> q;
        // for (const auto& qr : queries) {
        //     q.push({ qr[0], qr[0] });
        //     // ++track[qr[1]];
        // }
        // // std::unordered_set<int> tracking;
        for (const auto& [v, f] : indeg) {
            if (!f) q.push(v);
        }

        std::vector<std::unordered_set<int>> anc(numCourses);

        std::vector<std::vector<bool>> m(numCourses,
            std::vector<bool>(numCourses));
        
        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            for (const auto a : anc[v]) {
                m[a][v] = true;
            }

            for (const int to : e[v]) {
                anc[to].insert(anc[v].begin(), anc[v].end());
                anc[to].emplace(v);
                if (!--indeg[to]) {
                    q.push(to);
                }
            }

            anc[v].clear();
        }

        std::vector<bool> res;

        for (const auto& q : queries) {
            res.emplace_back(m[q[0]][q[1]]);
        }

        return res;
    }
};