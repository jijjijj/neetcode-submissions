class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>{});
        std::unordered_map<int, int> incoming;

        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].emplace_back(prereq[0]);
            ++incoming[prereq[0]];
            incoming[prereq[1]];
        }

        std::queue<int> q;
        for (auto [v, inc] : incoming) {
            if (!inc) q.push(v);
        }

        while (!q.empty()) {
            const auto v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (!--incoming[to]) q.push(to);
            }
        }

        for (auto [_, inc] : incoming) {
            if (inc) return false;
        }

        return true;
    }
};
