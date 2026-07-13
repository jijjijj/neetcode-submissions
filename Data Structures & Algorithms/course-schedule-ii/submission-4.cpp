class Solution {
public:
    vector<int> findOrder(int numCourses,
        vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> edges(numCourses);
        std::vector<int> indegree(numCourses);

        for (const auto& edge : prerequisites) {
            edges[edge[1]].emplace_back(edge[0]);
            ++indegree[edge[0]];
        }

        std::vector<int> result;

        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) {
                dfs(edges, result, indegree, i);
            }
        }

        return result;
    }

private:
    void dfs(std::vector<std::vector<int>>& edges,
        std::vector<int>& result,
        std::vector<int>& indegree,
        int v) {
        --indegree[v];

        result.emplace_back(v);

        for (int to : edges[v]) {
            --indegree[to];
            if (!indegree[to]) {
                dfs(edges, result, indegree, to);
            }
        }
    }
};
