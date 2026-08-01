class Solution {
public:
    // dijkstra
    // +bellmann-ford
    // +SPFA
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> e(n);
        for (const auto& f : flights) {
            e[f[0]].emplace_back(std::pair{ f[1], f[2] });
        }

        const int cInf =
            std::numeric_limits<int>::max();
        std::vector<std::vector<int>> prices(n,
            std::vector<int>(k + 2, cInf));
        prices[src][0] = 0;

        std::priority_queue<
            std::tuple<int, int, int>,
            std::vector<std::tuple<int, int, int>>,
            std::greater<>> q; // cost, stops, v
        q.push(std::tuple{ 0, 0, src });

        while (!q.empty()) {
            const auto [cost, stops, v] = q.top();
            q.pop();

            if (v == dst) return cost;

            if (stops > k) continue;

            for (const auto& [to, w] : e[v]) {
                if (cost + w < prices[to][stops + 1]) {
                    prices[to][stops + 1] = cost + w;
                    q.push(std::tuple{ prices[to][stops + 1], stops + 1, to });
                }
            }
        }

        return -1;
    }
};
