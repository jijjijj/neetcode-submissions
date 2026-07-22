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

        std::vector<int> dist(n, 9999999);

        while (!q.empty()) {
            auto [stops, cost, v] = q.top();
            q.pop();

            if (vis[v]) continue;
            vis[v] = true;

            if (stops > k) continue;

            for (const auto [to, c] : e[v]) {
                if (vis[to]) continue;

                dist[to] = std::min(dist[to], cost + c);

                q.push(std::tuple{ stops + 1, dist[to], to });
            }
        }

        return dist[dst] == 9999999 ? -1 : dist[dst];
    }
};
