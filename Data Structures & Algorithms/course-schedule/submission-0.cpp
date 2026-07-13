class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses, std::vector<int>{});

        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].emplace_back(prereq[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
        std::vector<bool> vis(numCourses);

            if (vis[i]) continue;

            std::queue<int> q;
            q.push(i);

            while (!q.empty()) {
                auto v = q.front();
                q.pop();

                vis[v] = true;

                for (int to : graph[v]) {
                    if (vis[to]) return false;

                    q.push(to);
                }
            }
        }

        return true;
    }
};
