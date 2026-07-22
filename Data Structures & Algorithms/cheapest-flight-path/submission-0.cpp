class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> e(n);

        for (const auto& f : flights) {
            e[f[0]].emplace_back(std::pair{ f[1], f[2] });
        }

        std::priority_queue<
            std::tuple<int, int, int>,  // stops, cost, v
            std::vector<std::tuple<int, int, int>>,
            std::greater<>> q;
        q.push(std::tuple{ 0, 0, src });
        std::vector<bool> vis(n);

        std::vector<std::pair<int, int>> dist(n,
            std::pair{ 9999, 9999999 });

        while (!q.empty()) {
            auto [stops, cost, v] = q.top();
            q.pop();

            if (vis[v]) continue;
            vis[v] = true;

            for (const auto [to, c] : e[v]) {
                if (vis[to]) continue;

                dist[to] = std::min(dist[to],
                    std::pair{ stops + 1, cost + c });

                q.push(std::tuple{ dist[to].first, dist[to].second, to });
            }
        }

        if (dist[dst].first > k + 1) return -1;

        return dist[dst].second;
    }
};
