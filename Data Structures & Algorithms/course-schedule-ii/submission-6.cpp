class Solution {
public:
    vector<int> findOrder(int n,
        vector<vector<int>>& prerequisites) {
        e.resize(n);
        std::vector<int> indeg(n);

        for (const auto& edge : prerequisites) {
            e[edge[1]].emplace_back(edge[0]);
            ++indeg[edge[0]];
        }

        std::queue<int> q;

        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) q.push(i);
            else ++total;
        }

        std::vector<int> res;

        while (!q.empty()) {
            const int v = q.front();
            q.pop();

            res.emplace_back(v);
            
            for (const int to : e[v]) {
                if (!--indeg[to]) {
                    --total;
                    q.push(to);
                }
            }
        }

        if (total) res.clear();

        return res;
    }

private:
    std::vector<std::vector<int>> e;
};
