class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> e(
            n + 1, std::vector<std::pair<int, int>>{});
        std::vector<int> dist(n + 1, 100001);

        for (const auto& t : times) {
            e[t[0]].emplace_back(std::pair{ t[1], t[2] });
        }

        dist[k] = 0;

        std::queue<int> q;
        q.push(k);

        std::vector<bool> enq(n + 1, false);

        while (!q.empty()) {
            auto v = q.front();
            q.pop();

            enq[v] = false;

            for (const auto& [to, d] : e[v]) {
                if (dist[to] > dist[v] + d) {
                    dist[to] = dist[v] + d;
                    
                    if (!enq[to]) {
                        enq[to] = true;
                        q.push(to);
                    }
                }
            }
        }

        const int max = *std::max_element(dist.begin() + 1, dist.end());

        return max == 100001 ? -1 : max;
    }
};
