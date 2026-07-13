class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, int> freq;
        for (int i = 0; i < numCourses; ++i) freq[i] = 0;

        std::vector<std::vector<int>> e(numCourses);
        for (const auto& edge : prerequisites) {
            e[edge[1]].emplace_back(edge[0]);
            ++freq[edge[0]];
        }

        std::vector<int> order;
        order.reserve(numCourses);

        std::queue<int> q;
        for (auto [v, inc] : freq) {
            if (!inc) q.push(v);
        }

        while (!q.empty()) {
            const int v = q.front();
            q.pop();
            
            order.emplace_back(v);

            for (int to : e[v]) {
                if (!--freq[to]) {
                    q.push(to);
                }
            }
        }

        if (order.size() != numCourses) order.clear();

        return order;
    }
};
