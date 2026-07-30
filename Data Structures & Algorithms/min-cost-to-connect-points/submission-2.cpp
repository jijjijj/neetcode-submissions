class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        std::vector<std::vector<std::tuple<int, int>>> e(n,
            std::vector<std::tuple<int, int>>{}); // dist, i

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int dist = std::abs(points[i][0] - points[j][0]) +
                    std::abs(points[i][1] - points[j][1]);
                
                e[i].emplace_back(std::tuple{ dist, j });
                e[j].emplace_back(std::tuple{ dist, i });
            }
        }

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> q;
        
        q.push(std::pair{ 0, 0 });

        int answer = 0;

        std::unordered_set<int> vis;
        while (!q.empty()) {
            const auto [_, i] = q.top();
            q.pop();

            if (vis.contains(i)) continue;
            vis.emplace(i);

            answer += _;

            for (const auto [d, to] : e[i]) {
                if (vis.contains(to)) continue;

                q.push({ d, to });
            }
        }

        return answer;
    }
};
