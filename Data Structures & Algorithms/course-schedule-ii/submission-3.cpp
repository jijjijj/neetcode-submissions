class Solution {
public:
    vector<int> findOrder(int numCourses,
        vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> edges(numCourses);
        
        for (const auto& edge : prerequisites) {
            edges[edge[0]].emplace_back(edge[1]);
        }

        std::vector<int> result;
        std::vector<bool> visited(numCourses);
        std::vector<bool> cycle(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (!dfs(result, visited, cycle, edges, i))
                    return {};
            }
        }

        return result;
    }

private:
    bool dfs(std::vector<int>& result,
        std::vector<bool>& visited,
        std::vector<bool>& cycle,
        const std::vector<std::vector<int>>& edges, int v) {
        if (cycle[v]) return false;
        if (visited[v]) return true;

        cycle[v] = true;

        for (const int to : edges[v]) {
            if (!dfs(result, visited, cycle, edges, to)) return false;
        }

        cycle[v] = false;
        visited[v] = true;
        result.emplace_back(v);

        return true;
    }
};
