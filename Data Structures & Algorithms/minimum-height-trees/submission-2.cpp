class Solution {
public:
    // bruteforce
    // +dp on trees
    // diameter
    // +peeling
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        e.resize(n);
        dp.resize(n, std::vector<int>(2, 0));

        for (const auto& edge : edges) {
            e[edge[0]].emplace_back(edge[1]);
            e[edge[1]].emplace_back(edge[0]);
        }

        const auto [v1, d1] = bfs(0);
        const auto [v2, d2] = bfs(v1);

        std::vector<int> path;
        find_path(v1, v2, -1, path);
        // return {};

        if (path.size() & 1) {
            return std::vector{ path[path.size() / 2] };
        }

        return std::vector{ path[path.size() / 2 - 1],
            path[path.size() / 2] };
    }

private:
    // v, dist
    std::pair<int, int> bfs(int v) {
        std::queue<std::pair<int, int>> q; // v, parent
        q.push({ v, -1 });

        int maxv = v;

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                const auto [v, p] = q.front();
                q.pop();

                for (int to : e[v]) {
                    if (to == p) continue;

                    q.push({ to, v });
                    maxv = to;
                }
            }
        }

        return { maxv, 0 };
    }

    bool find_path(int v1, int v2, int v1_parent,
        std::vector<int>& path) {
        if (v1 == v2) {
            // std::cout << v2 << " ";
            path.emplace_back(v2);
            return true;
        }

        for (const int to : e[v1]) {
            if (to == v1_parent) continue;

            if (find_path(to, v2, v1, path)) {
                // std::cout << v1 << " ";
                path.emplace_back(v1);
                return true;
            }
        }

        return false;
    }

    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> e;
};