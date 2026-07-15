class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> e(n + 1,
            std::vector<std::pair<int, int>>{});

        for (const auto& time : times) {
            e[time[0]].emplace_back(
                std::pair{ time[1], time[2] });
        }

        std::vector<int> dist(n + 1,
            std::numeric_limits<int>::max());
        dist[0] = dist[k] = 0;

        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<>> q;

        q.push({ 0, k });

        while (!q.empty()) {
            const auto [d, v] = q.top();
            q.pop();

            for (const auto& to : e[v]) {
                dist[to.first] = std::min(
                    dist[to.first], d + to.second);
                q.push({ dist[to.first], to.first });
            }
        }

        int max = std::ranges::max(dist);
        return max == std::numeric_limits<int>::max() ? -1 : max;
    }
};
